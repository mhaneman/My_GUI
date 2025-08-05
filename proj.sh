#!/bin/bash
PROJ="My_GUI"
TESTS="tests"

init() {
	echo "Init Project"
	./vcpkg/bootstrap-vcpkg.sh -disableMetrics
	./vcpkg/vcpkg install
}

build() {
	echo "Building Project"
    	mkdir build
    	cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
    	cmake --build ./build
}

run() {
	echo "Running Project"
	./build/$PROJ
}

clean() {
	echo "Cleaning Project"
	rm -rf ./build
}

while true; do
  clear
  tput bold; tput setaf 6
  echo "=== My GUI ==="
  tput sgr0
  echo

  PS3="Choose an option: "
  select opt in "Install Packages" "Build" "Run" "Build & Run" "Clean" "Exit"; do
    case $REPLY in
      1) init; break ;;
      2) build; break ;;
      3) run; break ;;
      4) build; run; break ;;
      5) clean; break ;;
      6) echo "Exiting..."; exit 0 ;;
      *) echo "❌ Invalid option"; sleep 1; break ;;
    esac
  done

  # Pause and redisplay menu
  echo
  read -rp "Press Enter to continue..."
done
