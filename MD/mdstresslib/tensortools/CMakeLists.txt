file(COPY tensortools     DESTINATION ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY} FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_WRITE WORLD_EXECUTE)
file(COPY LStensor.py     DESTINATION ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY} FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ GROUP_WRITE WORLD_READ WORLD_WRITE)

add_custom_target(copy_tensortools ALL
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/tensortools ${CMAKE_INSTALL_PREFIX}/bin/tensortools
    VERBATIM)

add_custom_target(copy_LStensor ALL
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/LStensor.py ${CMAKE_INSTALL_PREFIX}/bin/LStensor.py
    VERBATIM)