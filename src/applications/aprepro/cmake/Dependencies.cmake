if(CMAKE_PROJECT_NAME STREQUAL "SEACAS")
  SET(LIB_REQUIRED_DEP_PACKAGES Suplib)
else()
  SET(LIB_REQUIRED_DEP_PACKAGES SEACASSuplib)
endif()
SET(LIB_OPTIONAL_DEP_PACKAGES)
SET(TEST_REQUIRED_DEP_PACKAGES)
SET(TEST_OPTIONAL_DEP_PACKAGES)
SET(LIB_REQUIRED_DEP_TPLS)
SET(LIB_OPTIONAL_DEP_TPLS)
SET(TEST_REQUIRED_DEP_TPLS)
SET(TEST_OPTIONAL_DEP_TPLS)
