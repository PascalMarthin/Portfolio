#include "GameEngineWindow.h"
#include "GameEngineDebug.h"


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
} // 메시지 처리 함수

GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow();

GameEngineWindow::GameEngineWindow()
    : hInst_(nullptr)
    , hWnd_(nullptr)
    , WindowOn_(true)
    , HDC_(nullptr)
{
} // 초기화

GameEngineWindow::~GameEngineWindow()
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
} // 할당 해제

void GameEngineWindow::Off()
{
    WindowOn_ = false;
} // 윈도우 종료 함수

void GameEngineWindow::RegClass(HINSTANCE _hInst)
{
    // 윈도우 클래스 등록
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
    hInst_ = _hInst;
    // 부여받은 인스턴스 저장
    RegClass(_hInst);
    // 레지스터리 등록

    hWnd_ = CreateWindowExA(0L, "GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);
    // 윈도우(창) 생성

    HDC_ = GetDC(hWnd_);
    // HDC 권한 저장

    if (!hWnd_)
    {
        return;
    } // 생성이 안되었다면 반환
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