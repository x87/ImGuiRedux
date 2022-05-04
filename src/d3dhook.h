#pragma once
#pragma warning(push, 0)  
#include <d3d9.h>
#include <d3d11.h>
#include <GL/gl.h>
#pragma warning(pop)

class D3dHook
{
private:
    using f_EndScene = HRESULT(CALLBACK*)(IDirect3DDevice9*);
    using f_Present = HRESULT(CALLBACK*)(IDXGISwapChain*, UINT, UINT);
    using f_Reset = HRESULT(CALLBACK*)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
    using f_SwapBuffer = BOOL(CALLBACK*) (HDC hDc);

    static inline WNDPROC oWndProc;
    static inline f_Present oPresent;
    static inline f_EndScene oEndScene;
    static inline f_Reset oReset;
    static inline f_SwapBuffer oGlSwapBuffer;

    static inline bool mouseShown;
    static inline void* pCallbackFunc = nullptr;
    static inline HWND hwnd = NULL;

    static void CALLBACK ProcessFrame(void* ptr);
    static LRESULT CALLBACK hkWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static void ProcessMouse();

    // DirectX9
    static HRESULT CALLBACK hkEndScene(IDirect3DDevice9* pDevice);
    static HRESULT CALLBACK hkReset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);

    // DirectX11, Renderhook
    static HRESULT CALLBACK hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);

    // OpenGL
    static BOOL CALLBACK hkGlSwapBuffer(HDC hDc);
public:

    D3dHook() = delete;
    D3dHook(D3dHook const&) = delete;
    void operator=(D3dHook const&) = delete;

    static bool GetMouseState();
    static bool InjectHook(void *pCallback);
    static void RemoveHook();
    static void SetMouseState(bool state);
};
