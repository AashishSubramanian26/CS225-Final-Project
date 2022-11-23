from urllib.request import urlopen
import requests
from bs4 import BeautifulSoup
import re
import csv


class WebScrape():
    def __init__(self):
        self.parentLinks = []
        self.parentName = []
        self.childLinks = []
        self.childName = []
        self.NumLinksShared = []

    def scrapeWiki(self):

        url = 'https://en.wikipedia.org/wiki/Paris'
        website_url = requests.get(url).text
        soup = BeautifulSoup(website_url, "lxml")

        parentLink = 'https://en.wikipedia.org/wiki/Paris'
        parentTitle = 'Paris'

        childLinks = soup.find('href')
        childLinks = soup.find('href', {'class': 'wikitable sortable'})
        #for link in soup.find_all('p'):
        for link in soup.find_all('a'):
            if( (link.get('title') is not None) and ( ':' not in link.get('href') ) ):
                if(( ':' not in link.get('title')) and ( '?' not in link.get('href') )):
                    if(( 'Main_Page' not in link.get('href')) and ( 'identifier' not in link.get('title') ) and ( 'content' not in link.get('title') )):
                        print(link.get('href'))
                        print(link.get('title'))
        # http://example.com/elsie
        # http://example.com/lacie
        # http://example.com/tillie

        new = My_table.findAll('tr')

        for i in range(1, len(new)):
            string = str(new[i])
            start = string.find("title=") + 7
            end = string.find("\"", start, 900)
            altEnd = string.find(",", start, 900)
            if (end < altEnd):
                # print(string[start:end])
                self.cities.append(string[start:end])
            else:
                if (string[start:altEnd] == "Washington"):
                    self.cities.append("Washington DC")
                else:
                    # print(string[start:altEnd])
                    self.cities.append(string[start:altEnd])

    def createCSV(self):

        for i in range(len(self.cities)):
            self.dictionary[self.cities[i]] = self.cities[i]

        datafile = open("Cities.csv", "w")
        print("Hello")
        writer = csv.writer(datafile)
        writer.writerow(['City Name Column', 'City Name'])  # added
        for name, rating in self.dictionary.items():
            writer.writerow([name.lower(), rating])
        datafile.close()
        print('hello')
        return self.dictionary

d = WebScrape()
d.scrapeWiki()
#d.createCSV()