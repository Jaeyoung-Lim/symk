SRC_DIR := $(shell dirname "$(realpath $(lastword $(MAKEFILE_LIST)))")

build:
	docker build --file docker/Dockerfile --tag symktestenv .

run:
	docker run --network=host -it -v $(SRC_DIR):/root/dev/symk -w /root/dev/symk symktestenv bash
