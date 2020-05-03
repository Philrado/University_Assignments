# Cs1026A
# By Philip Radojcic
# Program called 'Sentiment Analysis'
#
# A program that analyzes twitter information, focusing on the content/words/phrases in
# tweets in order to determine popularity. This program aims to determine through
# sentiment Analysis, which timezone are is the happiest.

# Import to allow for later punctuation removal and .lower for sets.
import string

# Import for the graphics component
import happy_histogram

# Finds the timezone of the tweet.
def time_zone_finder(filename):
    zone = []
    with open(filename) as file:
        lines = file.readlines()
    for line in lines:
        # Splitting between the latitude and longitude.
        long = line.split(",")
        lat = line.split("[")
        long = ((long[1]).split("]"))[0]
        lat = ((lat[1]).split(","))[0]
        # Locating the specific zones based on latitude and longitude.
        if (float(lat) < 49.189787) and (float(lat) > 24.6608845):
            if (float(long) < -115.23628) and (float(long) > -125.242264):
                zone.append("pacific")
            elif (float(long) > -115.23628) and (float(long) < -101.998892):
                zone.append("mountain")
            elif (float(long) > -101.998892) and (float(long) < -87.518395):
                zone.append("central")
            elif (float(long) > -87.518395) and (float(long) < -67.444574):
                zone.append("eastern")
    return zone

# Analyzes the happiness score of a tweet.
def happiness_score(filename, wordsfile):
    happiness = []
    # Reads in the keywords with corresponding scores.
    with open(wordsfile) as file:
        lines = file.readlines()
    keyword = []
    score = []
    for line in lines:
        word = line.split(",")
        keyword.append(word[0])
        score.append(word[1])
    # Reads in the actual file in order to obtain the tweet.
    with open(filename) as file:
        lines = file.readlines()
    for line in lines:
        tweetline = line.split(" ")
        tempscore = 0
        keywordCount = 0
        # The 5th space till the end of the line is the tweet.
        for x in range(5, len(tweetline)):
            tweetline[x] = tweetline[x].translate(str.maketrans('','',string.punctuation))
            tweetline[x] = tweetline[x].lower()
            for y in range(0, len(keyword)):
                if tweetline[x] == keyword[y]:
                    tempscore += int(score[y])
                    keywordCount += 1
                    break
        # Makes sure to only count the tweets with keywords.
        if keywordCount == 0:
            happiness.append(0)
        else:
            happiness.append(tempscore/keywordCount)
    return happiness

# Compiles the individual functions of the program.
def main():
    # Setting the initial empty 'happiness score' values for each zone.
    zone = time_zone_finder('tweets.txt')
    score = happiness_score('tweets.txt', 'keywords.txt')
    pacific_tweets = 0
    mountain_tweets = 0
    central_tweets = 0
    eastern_tweets = 0
    pacific = 0
    mountain = 0
    central = 0
    eastern = 0
    # Uses the previous functions to total up the score and the amount of tweets per zone.
    for x in range(0, len(zone)):
        if score[x] > 0:
            if zone[x] == "pacific":
                pacific += score[x]
                pacific_tweets +=1
            elif zone[x] == "mountain":
                mountain += score[x]
                mountain_tweets +=1
            elif zone[x] == "central":
                central += score[x]
                central_tweets += 1
            elif zone[x] == "eastern":
                eastern += score[x]
                eastern_tweets += 1
    # Rounds the values to 1 decimal point.
    pacific = round(pacific/pacific_tweets, 1)
    mountain = round(mountain/mountain_tweets, 1)
    central = round(central/central_tweets, 1)
    eastern = round(eastern/eastern_tweets, 1)
    # Final output messages.
    print("")
    print("Pacific Happiness Score:  ", pacific)
    print("Pacific Total Tweets      ", pacific_tweets)
    print("")
    print("Mountain Happiness Score: ", mountain)
    print("Mountain Total Tweets:    ", mountain_tweets)
    print("")
    print("Central Happiness Score:  ", central)
    print("Central Total Tweets:     ", central_tweets)
    print("")
    print("Eastern Happiness Score:  ", eastern)
    print("Eastern Total Tweets:     ", eastern_tweets)
    # Draws the final picture display.
    happy_histogram.drawSimpleHistogram(eastern,central,mountain,pacific)

# Asks for the file inputs for keywords.txt and tweets.txt before going to the main.
print("")
file_input = input("Please input the name of the first file: ")
print("")
try:
   sample = open(file_input, 'r',encoding="utf-8")
except IOError:
    print("I'm sorry, that file name does not exist.")
    exit()
print("")
file_input2 = input("Please input the name of the second file: ")
print("")
try:
    sample = open(file_input2, 'r',encoding="utf-8")
    # Run's the program if both the files exist.
    main()
except IOError:
    print("I'm sorry, that file name does not exist.")
    exit()



