import csv

inpput_file = 'data/10000_realistic_tweets.csv'
output_file = 'data/bot.txt'

with open(inpput_file, 'r', encoding='latin-1') as csvfile, open(output_file, 'w', encoding='utf-8') as txtfile:
    reader = csv.reader(csvfile)

    for row in reader:
        tweet = row[0].strip()

        if len(tweet) > 0:
            tweet_clean = tweet.replace('\n', ' ').replace('\r', ' ')
            txtfile.write(tweet_clean + '\n')

print(f"Tweets have been extracted and saved to {output_file}.")