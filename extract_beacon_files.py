#!/usr/bin/env python3

import re
import os
import sys

def extract_files_from_patch(patch_file, target_dir):
    """Extract files from a git patch file"""
    
    with open(patch_file, 'r') as f:
        content = f.read()
    
    # Split by diff headers
    diffs = re.split(r'^diff --git', content, flags=re.MULTILINE)
    
    for diff in diffs[1:]:  # Skip first empty split
        lines = diff.split('\n')
        if not lines[0].strip():
            continue
            
        # Parse the diff header
        header = lines[0]
        if 'beacon_8mm' not in header and 'beacon_8mn' not in header:
            continue
            
        # Extract file path
        match = re.search(r'a/(.+)', header)
        if not match:
            continue
            
        file_path = match.group(1).split()[0]  # Take only the first part before any space
        full_path = os.path.join(target_dir, file_path)
        
        # Create directory if needed
        os.makedirs(os.path.dirname(full_path), exist_ok=True)
        
        # Extract file content (lines starting with +)
        file_content = []
        in_file_content = False
        
        for line in lines[1:]:
            if line.startswith('@@'):
                in_file_content = True
                continue
            elif line.startswith('diff --git'):
                break
            elif in_file_content and line.startswith('+'):
                file_content.append(line[1:])  # Remove the + prefix
            elif in_file_content and line.startswith(' '):
                file_content.append(line[1:])  # Remove the space prefix
        
        if file_content:
            with open(full_path, 'w') as f:
                f.write('\n'.join(file_content))
            print(f"Created: {full_path}")

if __name__ == "__main__":
    patch_file = "beacon-android-device.patch"
    target_dir = "."
    
    extract_files_from_patch(patch_file, target_dir)
