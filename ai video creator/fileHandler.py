import os
import pygame
from mp3Handler import createAnMp3, createAnMp3FromStr
from redditHandler import getPost

def listFileInFolder():
    current_directory = os.path.dirname(os.path.abspath(__file__))
    files = os.listdir(current_directory)
    print("""mp3 and mp4 Files existing in the folder are:
---------------------------------------------""")
    flag= 1
    for file_name in files:
        if isMp(file_name):
            tmp = str(flag) + " - " + file_name
            print(tmp)
            flag += 1
    
def deleteFile():
    fileName = input("Enter the file name (only mp3 or mp4 files!!!): ")
    if doesExist(fileName):
        if isMp(fileName):
            os.remove(fileName)

def isMp(fileName):
    _, extension = os.path.splitext(fileName)
    return extension.lower() == '.mp3' or extension.lower() == '.mp4'

def isMp3(fileName):
    _, extension = os.path.splitext(fileName)
    return extension.lower() == '.mp3'

def isMp4(fileName):
    _, extension = os.path.splitext(fileName)
    return extension.lower() == '.mp4'

def playMp3():
    fileName = input("Enter the file name (mp3 files only): ")
    if doesExist(fileName):
        if isMp3(fileName):
            print("please make sure your computer sound is at a good value so you can hear the mp3")
            tmp = "0"
            pygame.init()
            pygame.mixer.init()
            pygame.mixer.music.load(fileName)
            while tmp != 'q':
                pygame.mixer.music.play()
                tmp = input("Do you want to play the file again? ('q' if not) ")
            pygame.mixer.music.stop()
        else:
            print("File isn't a mp3")

def doesExist(fileName):
    if os.path.exists(fileName):
        return True
    else:
        print(f"File '{fileName}' does not exist. (Try to enter also the extension of the file. Ex: '.mp3','.mp4')")
        return False

def generate_unique_filename(base_name, extension):
    # Check if the base filename already exists in the folder
    if not os.path.exists(base_name + extension):
        return base_name + extension
    
    # If the base filename exists, generate a new filename with an incrementing counter
    counter = 1
    while True:
        new_filename = f"{base_name}_{counter}{extension}"
        if not os.path.exists(new_filename):
            return new_filename
        counter += 1

def deleteFileWithName(fileName):
    if doesExist(fileName):
        if isMp(fileName):
            os.remove(fileName)

def listAllmp4():
    current_directory = os.path.dirname(os.path.abspath(__file__))
    files = os.listdir(current_directory)
    output = """\nmp4 Files existing in the folder are:
---------------------------------------------"""
    flag= 1
    for file_name in files:
        if isMp4(file_name):
            output += "\n"+ file_name
            flag += 1
    
    if flag == 1:
        print("There isnt any mp4 files.")
        return False
    else:
        print(output)
        return True

def listAllmp3():
    current_directory = os.path.dirname(os.path.abspath(__file__))
    files = os.listdir(current_directory)
    output = """\nmp3 Files existing in the folder are:
---------------------------------------------"""
    flag= 1
    for file_name in files:
        if isMp3(file_name):
            output += "\n"+ file_name
            flag += 1
    
    if flag == 1:
        print("There isnt any mp3 files.")
        return False
    else:
        print(output)
        return True
  