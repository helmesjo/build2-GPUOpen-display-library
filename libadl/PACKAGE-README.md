# libadl - AMD Display Library (ADL) C API headers

This is a `build2` package for the
[`display-library`](https://github.com/GPUOpen-LibrariesAndSDKs/display-library)
C library. It provides the headers of the AMD Display Library (ADL) SDK, which
gives access to the low-level display driver functionality of AMD graphics
cards. The majority of the APIs in ADL wrap the private driver APIs, allowing
the library's client to access information related to the graphics hardware
associated with the system.

This package is licensed under the MIT License, as stated in the license
notice of each of the three upstream headers, which are the only upstream
files it contains. Note, however, that upstream also refers to the
[ADL SDK EULA](https://raw.githubusercontent.com/GPUOpen-LibrariesAndSDKs/display-library/18.0/Public-Documents/ADL%20SDK%20EULA.pdf)
for the terms and conditions of the SDK as a whole. The licensing statements
in the upstream repository have changed as follows:

* The initial GitHub release
  ([`d9ba026`](https://github.com/GPUOpen-LibrariesAndSDKs/display-library/commit/d9ba026),
  2018-01-17) included a repository-wide MIT `LICENSE.txt` as well as the
  EULA documents.

* ADL SDK 11.0
  ([`ba2f3eb`](https://github.com/GPUOpen-LibrariesAndSDKs/display-library/commit/ba2f3eb),
  2018-09-17) added an explicit MIT license notice to every header, which the
  headers still carry in 18.0.

* The EULA documents were removed as outdated
  ([`6b93141`](https://github.com/GPUOpen-LibrariesAndSDKs/display-library/commit/6b93141),
  2019-03-04) and later re-added, without explanation, while `LICENSE.txt`
  and `README.md` were deleted
  ([`418e44f`](https://github.com/GPUOpen-LibrariesAndSDKs/display-library/commit/418e44f),
  2020-02-05).

* ADL SDK 15.0
  ([`6c1a6b9`](https://github.com/GPUOpen-LibrariesAndSDKs/display-library/commit/6c1a6b9),
  2021-01-13) added `Public-Documents/README.md`, which refers to the EULA.

Whether the headers may be redistributed and packaged is an open question
upstream (see
[issue #41](https://github.com/GPUOpen-LibrariesAndSDKs/display-library/issues/41)).
None of the upstream documentation covered by the EULA is included in this
package.


## Usage

To start using `libadl` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libadl ^18.0.0
```

Then import the library in your `buildfile`:

```
import libs = libadl%lib{adl}
```


## Importable targets

This package provides the following importable targets:

```
lib{adl}
```

The ADL SDK headers, included without a subdirectory prefix
(`#include <adl_sdk.h>`, which includes `adl_structures.h` and
`adl_defines.h`). The package version is the ADL SDK version (`18.0.0` is
ADL SDK 18.0).

This library is header-only. The ADL implementation is part of the AMD
display driver (`atiadlxx.dll`, or `atiadlxy.dll` for 32-bit applications on
64-bit Windows) and the headers do not declare its functions. Instead, load
the ADL DLL at runtime with `LoadLibrary()` and resolve the functions with
`GetProcAddress()` using function pointer types declared by the application,
as in the upstream samples.

As in upstream, the headers target Windows and, in C, rely on the Windows
declarations (`wchar_t`, etc) being already included (`<windows.h>` must be
included before `<adl_sdk.h>`).


## Configuration variables

This package provides no configuration variables.
