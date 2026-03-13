# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [Unreleased]

### Added
- Basic image processing support (grayscale, resize, crop, normalize).
- Image I/O (load/save from common formats: PNG, JPEG).
- Simple computer vision algorithms: edge detection, thresholding, filters.
- Integration with Vix AI Tensor for tensor-based image operations.
- Unit tests for image transformations.

### Changed
- N/A

### Fixed
- N/A

---

## [0.1.0] - 2026-03-13

### Added
- Initial release of Vix AI Vision library.
- Core classes:
  - `Image` for representing 2D/3D image data.
  - `Filter` for applying convolution kernels.
  - `VisionUtils` for common image processing operations.
- CMake build system with:
  - Options for tests, warnings, and installation.
- Examples in `examples/` directory demonstrating image loading, processing, and saving.
- Basic integration with Vix AI Tensor for tensor operations on images.

### Changed
- N/A

### Fixed
- N/A
