from gtts import gTTS

def textToAudio(str,fileName,language="en"):
    audio = gTTS(str,lang=language)
    fileName = fileName + ".mp3"
    audio.save(fileName)

def getVoiceFormat():
    while True:
        try:
            voiceSelected = int(input("""please choose a voice language:
[1] Normal English
[2] American English
[3] British english
[4] Australian English           
Enter: """))
            if voiceSelected > 4 or voiceSelected < 1:
                raise
            else:
                break
        except:
            print("Invalid input... try again.")
            continue

    if voiceSelected == 1:
        return "en"
    elif voiceSelected == 2:
        return "en-us"
    elif voiceSelected == 3:
        return "en-uk"
    elif voiceSelected == 4:
        return "en-au"
    else:
        return "en"

def getFileName():
    return input("Enter the name for the file: ")

def createAnMp3():
    userInput = input("Enter a string to turn into an audio: ")
    textToAudio(userInput,getFileName(),getVoiceFormat())

def createAnMp3FromStr(str):
    textToAudio(str,getFileName(),getVoiceFormat())

def createAnMp3FromStrWithFileName(str,fileName):
    audio = gTTS(str,lang=getVoiceFormat())
    audio.save(fileName)

__all__ = ["createAnMp3"]