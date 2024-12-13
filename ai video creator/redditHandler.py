import praw

def checkIfPostExists(url):
    reddit = praw.Reddit(user_agent=True,client_id='wWx0F-N5MhfGjWQAu2RDUQ',
client_secret='TMEniEWg71XxLDxcOEbmX4YTVUuQKg',
username='ComprehensiveOwl9230',
password='a216743526')
    try:
        if url == "":
            print("You didnt enter a search on any post...")
            raise
        post = reddit.submission(url=url)
        return True
    except:
        print("Post doesn't exist.")
        raise
    
def getPost():
    reddit = praw.Reddit(user_agent=True,client_id='wWx0F-N5MhfGjWQAu2RDUQ',
client_secret='TMEniEWg71XxLDxcOEbmX4YTVUuQKg',
username='ComprehensiveOwl9230',
password='a216743526')
    url = input("Enter post link: ")
    if checkIfPostExists(url):
        post = reddit.submission(url=url)
        tmp = post.title + "\n" + post.selftext
        return tmp