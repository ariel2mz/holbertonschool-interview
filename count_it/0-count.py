#!/usr/bin/python3
import requests
"""kjkjk"""


def count_words(subreddit, word_list, after=None, counts=None):
    if counts is None:
        counts = {}
        for word in word_list:
            lw = word.lower()
            counts[lw] = counts.get(lw, 0)

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "reddit-keyword-counter"}
    params = {"after": after, "limit": 100}

    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )

    if response.status_code != 200:
        return

    data = response.json().get("data", {})
    children = data.get("children", [])

    for post in children:
        title = post["data"]["title"].lower().split()
        for word in word_list:
            lw = word.lower()
            counts[lw] += title.count(lw)

    after = data.get("after")

    if after:
        return count_words(subreddit, word_list, after, counts)

    filtered = {}
    for k, v in counts.items():
        if v > 0:
            filtered[k] = v

    if not filtered:
        return

    sorted_counts = sorted(
        filtered.items(),
        key=lambda x: (-x[1], x[0])
    )

    for word, count in sorted_counts:
        print(f"{word}: {count}")
