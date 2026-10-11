#include <stdlib.h>
#include <string.h>

/* As in upstream, in C the headers rely on the Windows declarations (wchar_t,
 * etc) being already included.
 */
#include <windows.h>

#include <adl_sdk.h>

#undef NDEBUG
#include <assert.h>

/* The memory allocation callback that the application passes to the
 * ADL_Main_Control_Create() and ADL2_Main_Control_Create() functions of the
 * ADL DLL.
 */
static void* __stdcall
memory_alloc (int n)
{
  return malloc ((size_t) n);
}

int main (void)
{
  /* Version.
   */
  assert (ADL_SDK_MAJOR_VERSION >= 18);

  /* Status codes.
   */
  assert (ADL_OK == 0 && ADL_ERR == -1 && ADL_ERR_NOT_INIT == -2);
  assert (ADL_TRUE == 1 && ADL_FALSE == 0);

  /* Memory allocation callback.
   */
  {
    ADL_MAIN_MALLOC_CALLBACK cb = &memory_alloc;
    void* p = cb (16);
    assert (p != NULL);
    free (p);
  }

  /* Context handle of the ADL2 functions.
   */
  {
    ADL_CONTEXT_HANDLE h = NULL;
    assert (h == NULL);
  }

  /* Adapter information.
   */
  {
    AdapterInfo ai;
    memset (&ai, 0, sizeof (ai));
    ai.iSize = (int) sizeof (ai);
    assert (ai.iAdapterIndex == 0 && ai.iPresent == 0);
    assert (sizeof (ai.strAdapterName) == ADL_MAX_PATH);
  }

  /* Application profile data (wide strings).
   */
  {
    ADLApplicationDataX2 ad;
    memset (&ad, 0, sizeof (ad));
    assert (sizeof (ad.strFileName) / sizeof (ad.strFileName[0]) ==
            ADL_APP_PROFILE_FILENAME_LENGTH);
    assert (ad.strPathName[0] == L'\0');
  }

  /* Performance metrics log.
   */
  {
    ADLPMLogDataOutput o;
    memset (&o, 0, sizeof (o));
    assert (sizeof (o.sensors) / sizeof (o.sensors[0]) ==
            ADL_PMLOG_MAX_SENSORS);
    assert (ADL_PMLOG_TEMPERATURE_INTAKE < ADL_PMLOG_MAX_SENSORS_REAL);
    assert (ADL_PMLOG_MAX_SENSORS_REAL <= ADL_PMLOG_MAX_SENSORS);
  }

  return 0;
}
