.PHONY: clean install

all: install

install: install-algo install-snip

install-algo:
	sudo ln -sf ${PWD}/algo/ /usr/local/include/

install-snip:
	mkdir -p ./.vscode/
	cd ./algo && python3 generate.py --out=../.vscode

clean:
	rm -rf ./.vscode/cpp.code-snippets
	sudo unlink /usr/local/include/algo
