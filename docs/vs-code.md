### Running VS Code on the Jetson Xavier
- The Jetson Xavier cannot run vscode by default on the Xavier, it must be run by code --no-sandbox
- An alias has been added to ~/.bashrc so that running "code" will run "code --no-sandbox". Add `alias code='code --no-sandbox'` to ~/.bashrc