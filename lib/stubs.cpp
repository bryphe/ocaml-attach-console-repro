#include <cstdint>
#include <cstdio>

#include <caml/alloc.h>
#include <caml/bigarray.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>
#include <caml/threads.h>

#ifdef WIN32
#include <Windows.h>
#endif

extern "C" {

CAMLprim value repro_AttachConsole() {
  CAMLparam0();
  int ret = 0;
#ifdef WIN32
  ret = AttachConsole(ATTACH_PARENT_PROCESS);
  FILE *fDummy;
  freopen_s(&fDummy, "CONIN$", "r", stdin);
  freopen_s(&fDummy, "CONOUT$", "w", stderr);
  freopen_s(&fDummy, "CONOUT$", "w", stdout);
#endif
  CAMLreturn(Val_int(ret));
}

CAMLprim value repro_AllocConsole() {
  CAMLparam0();
  int ret = 0;
#ifdef WIN32
  ret = AllocConsole();
  FILE *fDummy;
  freopen_s(&fDummy, "CONIN$", "r", stdin);
  freopen_s(&fDummy, "CONOUT$", "w", stderr);
  freopen_s(&fDummy, "CONOUT$", "w", stdout);
#endif
  CAMLreturn(Val_int(ret));
}

CAMLprim value repro_FreeConsole() {
  CAMLparam0();
  int ret = 0;
#ifdef WIN32
  ret = FreeConsole();
  FILE *fDummy;
  freopen_s(&fDummy, "CONIN$", "r", stdin);
  freopen_s(&fDummy, "CONOUT$", "w", stderr);
  freopen_s(&fDummy, "CONOUT$", "w", stdout);
#endif
  CAMLreturn(Val_int(ret));
}

CAMLprim value repro_NativePrint(value vString) {
  CAMLparam1(vString);

  printf("Printing from C: %s\n", String_val(vString));

  CAMLreturn(Val_unit);
}
}
