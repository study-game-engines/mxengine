// Copyright(c) 2019 - 2020, #Momo
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met :
// 
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and /or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include "Core/Macro/Macro.h"

#if defined(GLEW_BUILD)
#undef GLEW_BUILD
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace MxEngine
{
    #if defined(MXENGINE_DEBUG)
    #define GLCALL(x) GlClearErrors(); x; GlLogCall(#x, __FILE__, __LINE__)
    #define PUSH_DEBUG_GROUP(name) GlPushDebugGroup(name)
    #define POP_DEBUG_GROUP() GlPopDebugGroup()
    #else
    #define GLCALL(x) x
    #define PUSH_DEBUG_GROUP(name)
    #define POP_DEBUG_GROUP()
    #endif

    void GlClearErrors();

    bool GlLogCall(const char* function, const char* file, int line);

    void GlPushDebugGroup(const char* name);
    void GlPopDebugGroup();

    template<typename T>
    const char* TypeToString();

    template<typename T>
    unsigned int GetGLType();

    void APIENTRY PrintDebugInformation(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
}