import csv

inpput_file = 'data/training.1600000.processed.noemoticon.csv'
output_file = 'data/human.txt'

with open(inpput_file, 'r', encoding='latin-1') as csvfile, open(output_file, 'w', encoding='utf-8') as txtfile:
    reader = csv.reader(csvfile)

    for row in reader:
        tweet = row[5].strip()

        if len(tweet) > 0:
            tweet_clean = tweet.replace('\n', ' ').replace('\r', ' ')
            txtfile.write(tweet_clean + '\n')

print(f"Tweets have been extracted and saved to {output_file}.")