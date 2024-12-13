import os
from fileHandler import isMp4,isMp3,doesExist,generate_unique_filename,deleteFileWithName,listAllmp4,listAllmp3
from mp3Handler import createAnMp3FromStrWithFileName
import moviepy.editor as mpe
import pysrt

def time_to_seconds(time_obj):
    return time_obj.hours*3600 +time_obj.minutes*60 + time_obj.seconds + time_obj.miliseconds/1000

def create_subtitle_clips(subtitles, videosize,fontsize=24, font='Arial', color='white', debug = False):
    subtitle_clips = []

    for subtitle in subtitles:
        start_time = time_to_seconds(subtitle.start)
        end_time = time_to_seconds(subtitle.end)
        duration = end_time - start_time

        video_width, video_height = videosize
        
        text_clip = mpe.TextClip(subtitle.text, fontsize=fontsize, font=font, color=color, bg_color = 'none',size=(video_width*3/4, None), method='caption').set_start(start_time).set_duration(duration)
        subtitle_x_position = 'center'
        subtitle_y_position = video_height* 4 / 5 

        text_position = (subtitle_x_position, subtitle_y_position)                    
        subtitle_clips.append(text_clip.set_position(text_position))

    return subtitle_clips

def verifyFiles(videoPath,audioPath):
    if doesExist(videoPath) == False or doesExist(audioPath) == False:
        return False
    
    if isMp3(audioPath) and isMp4(videoPath):
        return True
    else:
        return False

def concatToOneVideo(fps=60):
    newVidName = getNewFileName()

    videoPath = getMp4File()
    audioPath = getMp3File()

    my_clip = mpe.VideoFileClip(videoPath)
    audio_background = mpe.AudioFileClip(audioPath)

    min_duration = min(my_clip.duration, audio_background.duration)
    min_duration_with_buffer = min_duration + 5 if min_duration + 5 <= audio_background.duration else min_duration
    vidClip = my_clip.subclip(0,min_duration_with_buffer)
    audClip = audio_background.subclip(0,min_duration_with_buffer)

    final_clip = vidClip.set_audio(audClip)
    final_clip.write_videofile(newVidName,fps=fps)

def concatToOneVideoWithSubtitles(postInText,fps=60):
    tmpFIlePath = generate_unique_filename("tmp",".mp3")
    try:
        newVidName = getNewFileName()

        videoPath = getMp4File() 

        createAnMp3FromStrWithFileName(postInText,tmpFIlePath)


        my_clip = mpe.VideoFileClip(videoPath)

        subtitles = pysrt.open()

        audio_background = mpe.AudioFileClip(tmpFIlePath)
        
        subtitle_clip = mpe.TextClip(postInText, fontsize=24, color='white', font='Arial')
        subtitle_clip = subtitle_clip.set_position(("bottom", 20)).set_duration(my_clip.duration)

        final_clip = my_clip.set_audio(audio_background)
        final_clip.write_videofile(newVidName,fps=fps)
        audio_background.close()
        deleteFileWithName(tmpFIlePath)
    except Exception as e:
        audio_background.close()
        deleteFileWithName(tmpFIlePath)

def makePostAnMp4NoSub(postInText,fps=60):
    tmpFIlePath = generate_unique_filename("tmp",".mp3")
    try:
 
        newVidName = getNewFileName()

        videoPath = getMp4File()

        createAnMp3FromStrWithFileName(postInText,tmpFIlePath)

        my_clip = mpe.VideoFileClip(videoPath)

        audio_background = mpe.AudioFileClip(tmpFIlePath)

        min_duration = min(my_clip.duration, audio_background.duration)
        min_duration_with_buffer = min_duration + 5 if min_duration + 5 <= audio_background.duration else min_duration

        vidClip = my_clip.subclip(0,min_duration_with_buffer)
        audClip = audio_background.subclip(0,min_duration_with_buffer)

        final_clip = vidClip.set_audio(audClip)
        final_clip.write_videofile(newVidName,fps=fps)
        audio_background.close()
        deleteFileWithName(tmpFIlePath)

    except Exception as e:
        audio_background.close()
        deleteFileWithName(tmpFIlePath)
        print("Exception caught:", e)

def getNewFileName():
    while True:
        newVidName = input("Enter the new name for the video to be created (without the extension): ")
        if ' ' in newVidName:
            print("Error: can't have spaces in a file name. Try again.\n")
            continue

        # Add the file extension
        newVidName += ".mp4"

        # Check if the file already exists
        if os.path.exists(newVidName):
            print("Error: A file with the same name already exists. Please choose a different name.\n")
            continue
        break

    print("\n")
    return newVidName

def getMp4File():
    if listAllmp4() == False:
        print("Try adding mp4 files to act as the background.")
        raise
    while True:
        videoPath = input("Enter the name for the video (mp4) file (with the extension): ")
        if doesExist(videoPath) == False or isMp4(videoPath) == False:
            print("File either doesn't exist or isn't an mp4.")
            print("Try again...\n")
            print("Remainder, here is all existing mp4 files in the folder.")
            listAllmp4()
            continue
        break
    return videoPath

def getMp3File():
    if listAllmp3() == False:
        print("Try adding mp3 files to act as the background.")
        raise
    while True:
        videoPath = input("Enter the name for the video (mp3) file (with the extension): ")
        if doesExist(videoPath) == False or isMp3(videoPath) == False:
            print("File either doesn't exist or isn't an mp3.")
            print("Try again...\n")
            print("Remainder, here is all existing mp3 files in the folder.")
            listAllmp3()
            continue
        break
    return videoPath
