import os

def rename_html_files(directory_path):
    # Get the list of all files in the directory
    try:
        files = os.listdir(directory_path)
    except FileNotFoundError:
        print(f"The directory {directory_path} does not exist.")
        return
    
    # Filter for .html files
    html_files = [f for f in files if f.endswith(".html")]
    
    # Sort the files to ensure consistent renaming order
    html_files.sort()

    # Rename each .html file in the directory
    for index, filename in enumerate(html_files, start=1):
        old_file_path = os.path.join(directory_path, filename)
        new_file_name = f"{index:02d}.html"
        new_file_path = os.path.join(directory_path, new_file_name)
        
        # Rename the file
        os.rename(old_file_path, new_file_path)
        print(f"Renamed {filename} to {new_file_name}")

# Take input for directory path
directory_path = input("Enter the directory path: ")
rename_html_files(directory_path)
