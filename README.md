# GPUOpen-display-library - AMD Display Library (ADL) C API headers

This is a `build2` package repository for
[`display-library`](https://github.com/GPUOpen-LibrariesAndSDKs/display-library),
the SDK of the AMD Display Library (ADL) for accessing low-level display
driver functionality of AMD graphics cards.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libadl` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libadl/PACKAGE-README.md) file.

The development setup for `GPUOpen-display-library` uses the standard `bdep`-based workflow.
For example:

```
git clone .../GPUOpen-display-library.git
cd GPUOpen-display-library

bdep init -C @msvc cc config.c=cl
bdep update
bdep test
```
