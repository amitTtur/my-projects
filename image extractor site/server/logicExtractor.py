import requests
from bs4 import BeautifulSoup
from urllib.parse import urlparse

# This function scans the given URL and returns image URLs of the site
def get_image_sources(soup, base_url):
    # Store all image URLs
    image_urls = []

    # Extract <img> tag images
    for img in soup.find_all('img'):
        src = img.get('src')
        if src:
            image_urls.append(src)

    # Extract background-image from inline styles
    for div in soup.find_all(style=True):
        style = div['style']
        if 'background-image' in style:
            start = style.find('url(') + 4
            end = style.find(')', start)
            if start != -1 and end != -1:
                url = style[start:end].strip('\'"')  # Remove quotes if any
                image_urls.append(url)

    # Extract from <picture> tags and <source> in video
    for picture in soup.find_all('picture'):
        for source in picture.find_all('source'):
            srcset = source.get('srcset')
            if srcset:
                image_urls.append(srcset.split()[0])  # Handle srcset

    # Extract Open Graph images from <meta> tags
    for meta in soup.find_all('meta', property="og:image"):
        content = meta.get('content')
        if content:
            image_urls.append(content)

    # Extract favicon or other icons
    for link in soup.find_all('link', rel=lambda x: x and 'icon' in x):
        href = link.get('href')
        if href:
            image_urls.append(href)

    # Handle custom attributes like data-src
    for img in soup.find_all(attrs={'data-src': True}):
        data_src = img['data-src']
        image_urls.append(data_src)

    # Convert relative URLs to absolute
    image_urls = [url if url.startswith('http') else base_url + url for url in image_urls]

    return image_urls

# New function to get video sources
def get_video_sources(soup, base_url):
    video_urls = []

    # Extract <video> tag sources
    for video in soup.find_all('video'):
        src = video.get('src')
        if src:
            video_urls.append(src)

        # Also check for nested <source> tags within <video>
        for source in video.find_all('source'):
            src = source.get('src')
            if src:
                video_urls.append(src)

    # Extract from standalone <source> tags (in case they’re outside <video>)
    for source in soup.find_all('source'):
        src = source.get('src')
        if src:
            video_urls.append(src)

    # Extract Open Graph videos from <meta> tags
    for meta in soup.find_all('meta', property="og:video"):
        content = meta.get('content')
        if content:
            video_urls.append(content)

    # Convert relative URLs to absolute
    video_urls = [url if url.startswith('http') else base_url + url for url in video_urls]

    return video_urls

# Function to get images and videos from a URL
# Function to get images and videos from a URL
def get_media_from_url(url):
    try:
        response = requests.get(url, timeout=10)
        response.raise_for_status()

        soup = BeautifulSoup(response.text, 'html.parser')
        base_url = url.rsplit('/', 1)[0] + '/'  # To resolve relative paths

        # Get images and videos
        image_urls = get_image_sources(soup, base_url)
        video_urls = get_video_sources(soup, base_url)

        # Combine image and video URLs into one list
        retArr = image_urls + video_urls  # Use + instead of extend

        print("Images found:", image_urls)
        print("Videos found:", video_urls)
        return retArr

    except requests.exceptions.Timeout:
        return ["ERROR","The request timed out."]
    except requests.exceptions.ConnectionError:
        return ["ERROR","Client connection error."]
    except requests.exceptions.HTTPError as e:
        return ["ERROR","Browser or requested site had a problem in the process."]
    except requests.exceptions.RequestException as e:
        return ["ERROR","Invalid URL given."]

def order_ambitious_url(url):
    # Parse the URL
    parsed_url = urlparse(url)

    # Check if the scheme is either empty or 'http'
    if parsed_url.scheme in ('', 'http'):
        # Change to 'https'
        return f"https://{parsed_url.netloc}{parsed_url.path}"

    return url  # Return the URL as is if already 'https' or not starting with a valid scheme

def getSiteMediaUrl(url):
    return get_media_from_url(order_ambitious_url(url))

def extractName(url):
    return url[url.rfind('/') + 1:] if '/' in url else url
