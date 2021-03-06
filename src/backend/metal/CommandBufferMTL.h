#pragma once

#include "../CommandBuffer.h"
#include "DeviceMTL.h"

CC_BACKEND_BEGIN

class RenderPipelineMTL;

class CommandBufferMTL : public CommandBuffer
{
public:
    CommandBufferMTL(DeviceMTL* deviceMTL);
    ~CommandBufferMTL();
    
    virtual void beginRenderPass(RenderPass* renderPass) override;
    virtual void setRenderPipeline(RenderPipeline* renderPipeline) override;
    virtual void setViewport(uint32_t x, uint32_t y, uint32_t w, uint32_t h) override;
    virtual void setVertexBuffer(uint32_t index, Buffer* buffer) override;
    virtual void setBindGroup(BindGroup* bindGroup) override;
    virtual void setIndexBuffer(Buffer* buffer) override;
    virtual void drawArrays(PrimitiveType primitiveType, uint32_t start,  uint32_t count) override;
    virtual void drawElements(PrimitiveType primitiveType, IndexFormat indexType, uint32_t count) override;
    virtual void endRenderPass() override;
    
private:
    void prepareDrawing() const;
    void setTextures() const;
    void doSetTextures(const std::vector<std::string>& textures, bool isVertex) const;
    void setUniformBuffer() const;
    uint32_t fillUniformBuffer(void* buffer, const std::vector<std::string>& uniforms) const;
    
    id<MTLCommandBuffer> _mtlCommandBuffer = nil;
    id<MTLCommandQueue> _mtlCommandQueue = nil;
    id<MTLRenderCommandEncoder> _mtlRenderEncoder = nil;
    id<MTLBuffer> _mtlIndexBuffer = nil;
    
    DeviceMTL* _deviceMTL = nullptr;
    RenderPipelineMTL* _renderPipelineMTL = nullptr;
    BindGroup* _bindGroup = nullptr;
};

CC_BACKEND_END
