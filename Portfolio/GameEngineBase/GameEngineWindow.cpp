#include "GameEngineWindow.h"
#include "GameEngineDebug.h"

// �޽��� ó�� �Լ�
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
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
        EndPaint(hWnd, &ps);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    default:
        break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow();

GameEngineWindow::GameEngineWindow() // �ʱ�ȭ
    : hInst_(nullptr)
    , hWnd_(nullptr)
    , WindowOn_(true)
    , HDC_(nullptr)
{
} 

GameEngineWindow::~GameEngineWindow() // �Ҵ� ����
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

// ������ ���� �Լ�
void GameEngineWindow::Off() 
{
    WindowOn_ = false;
} 

// ������ Ŭ���� ���
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
        MsgBoxAssert("�����츦 2�� ������ �߽��ϴ�.");
        return;
    }

    Title_ = _Title;
    // Ŭ���� ����� 1���� �Ϸ��� ģ �ڵ�
    // �ο����� �ν��Ͻ� ����
    hInst_ = _hInst;
 
    // �������͸� ���
    RegClass(_hInst);

    // ������(â) ����
    hWnd_ = CreateWindowExA(0L, "GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);

    // HDC ���� ����
    HDC_ = GetDC(hWnd_);

    // ������ �ȵǾ��ٸ� ��ȯ
    if (!hWnd_)
    {
        return;
    } 
}

void GameEngineWindow::ShowGameWindow()
{
    if (nullptr == hWnd_)
    {
        MsgBoxAssert("���� �����찡 ��������� �ʾҽ��ϴ� ȭ�鿡 ����Ҽ� �����ϴ�.");
        return;
    }

    ShowWindow(hWnd_, SW_SHOW); // ������ ���
    UpdateWindow(hWnd_); 
}


void GameEngineWindow::MessageLoop(void(*_InitFunction)(), void(*_LoopFunction)())
{
    // ������ ��������
    // ���� �غ��Ұ� �ִٸ� �غ��Լ��� �����ش޶�.

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
        } // �޽��� ó��, �ൿ�� ������ ��ȯ

        // ���⼭ ���������� �������?

        if (nullptr == _LoopFunction)
        {
            continue;
        }

        _LoopFunction();
    }
}


void GameEngineWindow::SetWindowScaleAndPosition(float4 _Pos, float4 _Scale)
{
    // �޴��� 

    Scale_ = _Scale;
    RECT Rc = { 0, 0,  _Scale.ix(),  _Scale.iy() };

    // 1280 + �޴���

    AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);



    SetWindowPos(hWnd_, nullptr, _Pos.ix(), _Pos.iy(), Rc.right - Rc.left, Rc.bottom - Rc.top, SWP_NOZORDER);
}