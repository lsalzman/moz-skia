/*
 * Copyright 2022 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef skgpu_render_TessellateCurvesRenderStep_DEFINED
#define skgpu_render_TessellateCurvesRenderStep_DEFINED

#include "experimental/graphite/src/Renderer.h"

namespace skgpu {

class TessellateCurvesRenderStep final : public RenderStep {
public:
    // TODO: If this takes DepthStencilSettings directly and a way to adjust the flags to specify
    // that it performs shading, this RenderStep definition can be shared between the stencil and
    // the convex rendering variants.
    TessellateCurvesRenderStep(bool evenOdd);

    ~TessellateCurvesRenderStep() override;

    const char* name() const override { return "TessellateCurvesRenderStep"; }

    const char* vertexSkSL() const override;
    void writeVertices(DrawWriter*,
                       const SkIRect&,
                       const Transform&,
                       const Shape&) const override;
    sk_sp<SkUniformData> writeUniforms(Layout,
                                       const SkIRect&,
                                       const Transform&,
                                       const Shape&) const override;
};

}  // namespace skgpu

#endif // skgpu_render_TessellateCurvesRenderStep_DEFINED