#Copyright (C) 2008 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#
# This file should set PRODUCT_MAKEFILES to a list of product makefiles
# to expose to the build system.  LOCAL_DIR will already be set to
# the directory containing this file.
#
# This file may not rely on the value of any variable other than
# LOCAL_DIR; do not use any conditionals, and do not look up the
# value of any variable that isn't set in this file or in a file that
# it includes.
#

# Copied from build/target/product/AndroidProducts.mk

PRODUCT_MAKEFILES := \
  $(LOCAL_DIR)/beacon_8mm/beacon_8mm.mk \
  $(LOCAL_DIR)/beacon_8mn/beacon_8mn.mk \
  $(LOCAL_DIR)/evk_8mq/evk_8mq.mk \
  $(LOCAL_DIR)/evk_8mm/evk_8mm.mk \
  $(LOCAL_DIR)/evk_8mn/evk_8mn.mk \
  $(LOCAL_DIR)/evk_8mp/evk_8mp.mk

COMMON_LUNCH_CHOICES := \
  beacon_8mm-user \
  beacon_8mm-userdebug \
  beacon_8mn-user \
  beacon_8mn-userdebug \
  evk_8mq-nxp_stable-user \
  evk_8mq-nxp_stable-userdebug \
  evk_8mm-nxp_stable-user \
  evk_8mm-nxp_stable-userdebug \
  evk_8mn-nxp_stable-user \
  evk_8mn-nxp_stable-userdebug \
  evk_8mp-nxp_stable-user \
  evk_8mp-nxp_stable-userdebug
