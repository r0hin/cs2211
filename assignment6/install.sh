#!/bin/bash

# Change to the src directory
cd src || {
    echo "Error: src directory not found"
    exit 1
}

# Step 1: Build the program using make
echo "Building gcal..."
make

# Check if make was successful
if [ $? -ne 0 ]; then
    echo "Error: Build failed"
    exit 1
fi

# Step 2: Create installation directory if it doesn't exist
INSTALL_DIR="$HOME/.local/bin"
echo "Creating installation directory $INSTALL_DIR (if it doesn't exist)..."
mkdir -p "$INSTALL_DIR"

# Step 3: Copy the executable to the installation directory
echo "Installing gcal to $INSTALL_DIR..."
cp gcal "$INSTALL_DIR/"

# Step 4: Add installation directory to PATH in ~/.bashrc if not already present
BASHRC="$HOME/.bashrc"
PATH_LINE='export PATH="$HOME/.local/bin:$PATH"'

# Check if .bashrc exists, create if it doesn't
if [ ! -f "$BASHRC" ]; then
    touch "$BASHRC"
fi

# Add PATH only if it's not already in .bashrc
if ! grep -q "$PATH_LINE" "$BASHRC"; then
    echo "Adding $INSTALL_DIR to PATH in ~/.bashrc..."
    echo "$PATH_LINE" >> "$BASHRC"
    echo "Please run 'source ~/.bashrc' or restart your terminal to update PATH"
else
    echo "$INSTALL_DIR is already in PATH"
fi

echo "Installation complete! You can now use 'gcal' from anywhere in the terminal."
