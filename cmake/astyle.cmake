add_custom_target(astyle
                  COMMAND astyle
                          --options=${PROJECT_SOURCE_DIR}/utilities/.astylerc
                          ${PROJECT_SOURCE_DIR}/src/*.cpp
                          ${PROJECT_SOURCE_DIR}/include/**/*
                  COMMAND echo "Formatting files finished successfully"
                  )