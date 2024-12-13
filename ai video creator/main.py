import sys
from fileHandler import listFileInFolder,deleteFile,playMp3
from mp3Handler import createAnMp3,createAnMp3FromStr
from redditHandler import getPost
from concatVideoHandler import concatToOneVideo,concatToOneVideoWithSubtitles,makePostAnMp4NoSub

def showMenu():
    print("\n")
    while True:
        try:
            option = int(input("""Menu:
[0] Exit
[1] List mp3 and mp4 files in the current folder.
[2] Create an mp3 file
[3] Delete an mp3 or mp4 file
[4] Play an mp3 file    
[5] Get a post title and content  
[6] Turn a post into an mp3    
[7] concat mp3 and mp4 files      
[8] make post an mp4 (isn't implemented yet)
[9] make post an mp4 with no subtitles                
Enter: """))
            if option > 9 or option < 0:
                raise
            else:
                print("\n")
                return option
        except:
            print("Invalid input... try again.\n")
            continue

def goToOption(option):
    if option == 1:
        listFileInFolder()
    elif option == 2:
        createAnMp3()
    elif option == 3:
        deleteFile()
    elif option == 4:
        playMp3()
    elif option == 5:
        print(getPost())
    elif option == 6:
        createAnMp3FromStr(getPost())
    elif option == 7:
        concatToOneVideo()
    elif option == 8:
        concatToOneVideoWithSubtitles(getPost())
    elif option == 9:
        makePostAnMp4NoSub(getPost())
    else:
        return False
    return True

def main():
    exitFlag = True
    while exitFlag:
        try:
            exitFlag = goToOption(showMenu())
        except Exception as e:
            print("Exception caught:", e)
            pass


if __name__ == '__main__':
    main()