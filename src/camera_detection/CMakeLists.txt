cmake_minimum_required(VERSION 3.8)
project(camera_detection)

# Encontrar dependencias
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(camera_detection_interfaces REQUIRED)

# Compilar el ejecutable panorama_robusto
add_executable(panorama_robusto src/panorama_robusto.cpp)
target_link_libraries(panorama_robusto ${OpenCV_LIBS})

# Instalar el ejecutable en lib/camera_detection
install(TARGETS panorama_robusto
  DESTINATION lib/${PROJECT_NAME}
)

# Instalar el script Python también en lib/camera_detection
install(PROGRAMS scripts/detection_service.py
  DESTINATION lib/${PROJECT_NAME}
)

# Para que ros2 run encuentre el ejecutable (detection_service)
install(DIRECTORY scripts/
  DESTINATION lib/${PROJECT_NAME}
)

# Instalar archivos de launch (si los hay)
# install(DIRECTORY launch/
#   DESTINATION share/${PROJECT_NAME}/launch
# )

ament_package()