#include "GameEngineWindow.h"

// 메시지 처리 함수
LRESULT CALLBACK MessageProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        GameEngineWindow::GetInst().Off();
        return DefWindowProc(hWnd, message, wParam, lParam);
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hWnd, &ps);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    default:
        break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow();

GameEngineWindow::GameEngineWindow() // 초기화
    : hInst_(nullptr)
    , hWnd_(nullptr)
    , WindowOn_(true)
    , HDC_(nullptr)
{
} 

GameEngineWindow::~GameEngineWindow() // 할당 해제
{
    if (nullptr != HDC_)
    {
        ReleaseDC(hWnd_, HDC_);
        HDC_ = nullptr;
    }

    if (nullptr != hWnd_)
    {
        DestroyWindow(hWnd_);
        hWnd_ = nullptr;
    }
} 

// 윈도우 종료 함수
void GameEngineWindow::Off() 
{
    WindowOn_ = false;
} 

// 윈도우 클래스 등록
void GameEngineWindow::RegClass(HINSTANCE _hInst)  
{
  
    WNDCLASSEXA wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = MessageProcess;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInst;
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "GameEngineWindowClass";
    wcex.hIconSm = nullptr;
    RegisterClassExA(&wcex);
}

void GameEngineWindow::CreateGameWindow(HINSTANCE _hInst, const std::string& _Title)
{
    if (nullptr != hInst_)
    {
        MsgBoxAssert("윈도우를 2번 띄우려고 했습니다.");
        return;
    }

    Title_ = _Title;
    // 클래스 등록은 1번만 하려고 친 코드
    // 부여받은 인스턴스 저장
    hInst_ = _hInst;
 
    // 레지스터리 등록
    RegClass(_hInst);

    // 윈도우(창) 생성
    hWnd_ = CreateWindowExA(0L, "GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);

    // HDC 권한 저장
    HDC_ = GetDC(hWnd_);

    // 생성이 안되었다면 반환
    if (!hWnd_)
    {
        return;
    } 
}

void GameEngineWindow::ShowGameWindow()
{
    if (nullptr == hWnd_)
    {
        MsgBoxAssert("메인 윈도우가 만들어지지 않았습니다 화면에 출력할수 없습니다.");
        return;
    }

    ShowWindow(hWnd_, SW_SHOW); // 윈도우 출력
    UpdateWindow(hWnd_); 
}


void GameEngineWindow::MessageLoop(void(*_InitFunction)(), void(*_LoopFunction)())
{
    // 루프를 돌기전에
    // 뭔가 준비할게 있다면 준비함수를 실행해달라.

    if (nullptr != _InitFunction)
    {
        _InitFunction();
    }

    MSG msg;

    while (WindowOn_)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } // 메시지 처리, 행동이 없으면 반환

        // 여기서 무슨게임을 돌릴까요?

        if (nullptr == _LoopFunction)
        {
            continue;
        }

        _LoopFunction();
    }
}


void GameEngineWindow::SetWindowScaleAndPosition(float4 _Pos, float4 _Scale)
{
    // 메뉴바 

    Scale_ = _Scale;
    RECT Rc = { 0, 0,  _Scale.ix(),  _Scale.iy() };

    // 1280 + 메뉴바

    AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);



    SetWindowPos(hWnd_, nullptr, _Pos.ix(), _Pos.iy(), Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOZORDER);
}