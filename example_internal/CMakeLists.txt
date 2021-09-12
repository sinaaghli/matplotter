add_executable(plotter plotter.cpp)

target_link_libraries(plotter ${LIBRARY_NAME})

install(
  TARGETS plotter
  # EXPORT ${PROJECT_EXPORT} # uncomment in order to export target
  RUNTIME DESTINATION bin
  COMPONENT "${INSTALL_BIN_DIR}"
)

