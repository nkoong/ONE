/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Copyright (c) 2016-2018 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __ARM_COMPUTE_NEPRELUKERNEL_H__
#define __ARM_COMPUTE_NEPRELUKERNEL_H__

#include "arm_compute/core/NEON/INEKernel.h"

namespace arm_compute
{
class ITensor;

/** Interface for the kernel to perform Parametric Rectified Linear Unit
 *
 * Result is computed by:
 * @f[ output(x) = alpha * x for x < 0, output(x) = x for x >= 0 @f]
 */
class NEPReLUKernel : public INEKernel
{
public:
  const char *name() const override { return "NEPReLUKernel"; }
  /** Default constructor */
  NEPReLUKernel();
  /** Prevent instances of this class from being copied (As this class contains pointers) */
  NEPReLUKernel(const NEPReLUKernel &) = delete;
  /** Prevent instances of this class from being copied (As this class contains pointers) */
  NEPReLUKernel &operator=(const NEPReLUKernel &) = delete;
  /** Allow instances of this class to be moved */
  NEPReLUKernel(NEPReLUKernel &&) = default;
  /** Allow instances of this class to be moved */
  NEPReLUKernel &operator=(NEPReLUKernel &&) = default;
  /** Initialise the kernel's inputs and output
   *
   * @param[in]  input Input tensor. Data type supported: QASYMM8/F32
   * @param[in]  alpha Alpha tensor. Data types supported: Same as @p input
   * @param[out] output Output tensor. Data types supported: Same as @p input
   */
  void configure(const ITensor *input, const ITensor *alpha, ITensor *output);

  // Inherited methods overridden:
  void run(const Window &window, const ThreadInfo &info) override;

  /** Static function to check if given info will lead to a valid configuration of @ref
   * NEPReLUKernel.h
   *
   * @param[in] input  Input tensor input info. Data types supported: QASYMM8/F32.
   * @param[in] alpha  Alpha tensor input info. Data types supported: Same as @p input.
   * @param[in] output Output tensor info. Data types supported: Same as @p input.
   *
   * @return a Status
   */
  static Status validate(const ITensorInfo *input, const ITensorInfo *alpha,
                         const ITensorInfo *output);
  static Status validate_arguments(const ITensorInfo &input, const ITensorInfo &alpha,
                                   const ITensorInfo &output);

private:
  const ITensor *_input; /**< Source tensor */
  const ITensor *_alpha; /**< Alpha tensor */
  ITensor *_output;      /**< Destination tensor */
};
} // namespace arm_compute
#endif /* __ARM_COMPUTE_NEPRELUKERNEL_H__ */
