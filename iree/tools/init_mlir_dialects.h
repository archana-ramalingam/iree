// Copyright 2020 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// This files defines a helper to trigger the registration of dialects to
// the system.
//
// Based on MLIR's InitAllDialects but without dialects we don't care about.

#ifndef IREE_TOOLS_INIT_MLIR_DIALECTS_H_
#define IREE_TOOLS_INIT_MLIR_DIALECTS_H_

#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/ArmNeon/ArmNeonDialect.h"
#include "mlir/Dialect/Bufferization/IR/Bufferization.h"
#include "mlir/Dialect/GPU/GPUDialect.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "mlir/Dialect/Linalg/IR/Linalg.h"
#include "mlir/Dialect/Math/IR/Math.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Quant/QuantOps.h"
#include "mlir/Dialect/SCF/SCF.h"
#include "mlir/Dialect/SPIRV/IR/SPIRVDialect.h"
#include "mlir/Dialect/Shape/IR/Shape.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/Dialect/Tensor/IR/Tensor.h"
#include "mlir/Dialect/Tensor/IR/TensorInferTypeOpInterfaceImpl.h"
#include "mlir/Dialect/Tosa/IR/TosaOps.h"
#include "mlir/Dialect/Vector/VectorOps.h"
#include "mlir/IR/Dialect.h"

#ifdef IREE_HAVE_EMITC_DIALECT
#include "mlir/Dialect/EmitC/IR/EmitC.h"
#endif  // IREE_HAVE_EMITC_DIALECT

namespace mlir {

// Add all the MLIR dialects to the provided registry.
inline void registerMlirDialects(DialectRegistry &registry) {
  // clang-format off
  registry.insert<AffineDialect,
                  bufferization::BufferizationDialect,
                  gpu::GPUDialect,
                  LLVM::LLVMDialect,
                  linalg::LinalgDialect,
                  math::MathDialect,
                  memref::MemRefDialect,
                  scf::SCFDialect,
                  quant::QuantizationDialect,
                  spirv::SPIRVDialect,
                  arm_neon::ArmNeonDialect,
                  StandardOpsDialect,
                  mlir::arith::ArithmeticDialect,
                  vector::VectorDialect,
                  tensor::TensorDialect,
                  tosa::TosaDialect,
                  shape::ShapeDialect>();
  // clang-format on
  tensor::registerInferTypeOpInterfaceExternalModels(registry);

#ifdef IREE_HAVE_EMITC_DIALECT
  registry.insert<emitc::EmitCDialect>();
#endif  // IREE_HAVE_EMITC_DIALECT
}

}  // namespace mlir

#endif  // IREE_TOOLS_INIT_MLIR_DIALECTS_H_
