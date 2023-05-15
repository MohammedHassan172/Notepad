#include <windows.h>
#include <time.h>
#include <stdio.h>


const char g_szClassName[] = "myWindowClass";
HWND Textbox,reset,Italics,bold,under_line,strike_out,font_up,font_down;
HFONT defal,defal2;


HFONT test;

int boldness = 0;
DWORD ITA = 0;
DWORD UND = 0;
DWORD STK = 0;
int size = 0;
int test1 = 0;



void chnge_font()
{
    HDC hdc;
    long lfHeight;

    hdc = GetDC(NULL);
    lfHeight = -MulDiv(10 + size, GetDeviceCaps(hdc, LOGPIXELSY), 72);
    ReleaseDC(NULL, hdc);
    test = CreateFont(lfHeight, 0, 0, 0, boldness, ITA, UND, STK, 0, 0, 0, 0, 0, "Consolas");
    SendMessage(Textbox,WM_SETFONT,(WPARAM)test, TRUE);
}

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

    switch(msg)
    {

        case WM_CREATE:
            Textbox = CreateWindow("EDIT",
                                   "",
                                  WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL,
                                   0,0,
                                   500,500,
                                   hwnd,NULL,NULL,NULL);
                    reset = CreateWindow("BUTTON",
                                      "reset",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      508,10,70,20,
                                      hwnd,(HMENU) 1, NULL,NULL);
                    Italics = CreateWindow("BUTTON",
                                      "Italics",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      508,40,70,20,
                                      hwnd,(HMENU) 2, NULL,NULL);
                    bold = CreateWindow("BUTTON",
                                      "Bold",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      508,70,70,20,
                                      hwnd,(HMENU) 3, NULL,NULL);
                    under_line = CreateWindow("BUTTON",
                                      "underline",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      508,100,70,20,
                                      hwnd,(HMENU) 4, NULL,NULL);
                    strike_out = CreateWindow("BUTTON",
                                      "strike out",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      508,130,75,20,
                                      hwnd,(HMENU) 5, NULL,NULL);

                    font_up = CreateWindow("BUTTON",
                                      "+",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      508,160,30,30,
                                      hwnd,(HMENU) 6, NULL,NULL);

                    font_down = CreateWindow("BUTTON",
                                      "-",
                                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                                      508,200,30,30,
                                      hwnd,(HMENU) 7, NULL,NULL);

            break;

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
            case 1 :
                boldness = 0;
                ITA = 0;
                UND = 0;
                STK = 0;
                size = 0;
                chnge_font();
             break;

            case 2 :
                ITA = TRUE;
                chnge_font();
                 break;

            case 3 :
                boldness = 700;
                chnge_font();
                 break;
           case 4 :
                UND = TRUE;
                chnge_font();
                 break;
           case 5 :
                STK = TRUE;
                chnge_font();
                 break;
           case 6 :
                size++;
                chnge_font();
                 break;
           case 7 :
                size--;
                chnge_font();
                test1 = 1;
                 break;
            }
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    

    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;



    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window


     HDC hdc;
    long lfHeight;

    hdc = GetDC(NULL);
    lfHeight = -MulDiv(10, GetDeviceCaps(hdc, LOGPIXELSY), 72);
    ReleaseDC(NULL, hdc);


    defal = CreateFont(lfHeight, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, "Consolas");
    defal2 = CreateFont(lfHeight, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, "Consolas");



    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Notepad",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 610, 540,
        NULL, NULL, hInstance, NULL);
        SendMessage(Textbox,WM_SETFONT,(WPARAM)defal2, TRUE);
        SendMessage(reset,WM_SETFONT,(WPARAM)defal, TRUE);
        SendMessage(Italics,WM_SETFONT,(WPARAM)defal, TRUE);
        SendMessage(bold,WM_SETFONT,(WPARAM)defal, TRUE);
        SendMessage(under_line,WM_SETFONT,(WPARAM)defal, TRUE);
        SendMessage(strike_out,WM_SETFONT,(WPARAM)defal, TRUE);
        SendMessage(font_up,WM_SETFONT,(WPARAM)defal, TRUE);
        SendMessage(font_down,WM_SETFONT,(WPARAM)defal, TRUE);
    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }




    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

        int k = 0;




        while(GetMessage(&Msg, NULL, 0, 0) > 0)
        {
          TranslateMessage(&Msg);
          DispatchMessage(&Msg);
        }



    return Msg.wParam;
}
