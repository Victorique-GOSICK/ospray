// ======================================================================== //
// Copyright 2009-2015 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#include "AmbientLight.h"
#include "AmbientLight_ispc.h"

namespace ospray {
  //!Construct a new AmbientLight object
  AmbientLight::AmbientLight()
    : color(1.f, 1.f, 1.f)
    , intensity(1.f)
  {
    ispcEquivalent = ispc::AmbientLight_create(this);
  }

  //!Commit parameters understood by the base AmbientLight class
  void AmbientLight::commit() {
    color     = getParam3f("color", vec3f(1.f, 1.f, 1.f));
    intensity = getParam1f("intensity", 1.f);
    
    ispc::AmbientLight_set(getIE(), (ispc::vec3f&)color, intensity);
  }
}
