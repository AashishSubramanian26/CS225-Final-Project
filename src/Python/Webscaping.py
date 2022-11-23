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
        self.startingIndex = []

    def scrapeWiki(self):

        url = 'https://en.wikipedia.org/wiki/Paris'
        website_url = requests.get(url).text
        soup = BeautifulSoup(website_url, "lxml")

        parentLink = 'https://en.wikipedia.org/wiki/Paris'
        parentTitle = 'Paris'
        self.startingIndex.append(0)

        for link in soup.find_all('a'):
            if( (link.get('title') is not None) and ( ':' not in link.get('href') ) ):
                if(( ':' not in link.get('title')) and ( '?' not in link.get('href') )):
                    if(( 'Main_Page' not in link.get('href')) and ( 'identifier' not in link.get('title') ) and ( 'content' not in link.get('title') )):
                        if(link.get('title') not in self.childName):
                            self.parentLinks.append(parentLink)
                            self.parentName.append(parentTitle)
                            self.childLinks.append('https://en.wikipedia.org'+ link.get('href'))
                            self.childName.append(link.get('title'))

        for i in range(10):
            url = self.childLinks[i]
            website_url = requests.get(url).text
            soup = BeautifulSoup(website_url, "lxml")

            parentLink = url
            parentTitle = self.childName[i]
            self.startingIndex.append(len(self.childName))

            for link in soup.find_all('a'):
                if ((link.get('title') is not None) and (':' not in link.get('href'))):
                    if ((':' not in link.get('title')) and ('?' not in link.get('href'))):
                        if (('Main_Page' not in link.get('href')) and ('identifier' not in link.get('title')) and (
                                'content' not in link.get('title'))):
                            #if (link.get('title') not in self.childName):
                            self.parentLinks.append(parentLink)
                            self.parentName.append(parentTitle)
                            self.childLinks.append('https://en.wikipedia.org' + link.get('href'))
                            self.childName.append(link.get('title'))
        print(self.parentLinks)
        print(self.parentName)
        print(self.childLinks)
        print(self.childName)
        print(self.startingIndex)
        print(self.parentName[7057])
        
        #idea for number of links shared
        #We need to keep track of how many times the parent and child links have that are matching
        #we can use something checking if a parent link is equal to a childname? Something like that

    def createCSV(self):


        datafile = open("Dataset.csv", "w")
        print("Hello")
        writer = csv.writer(datafile)
        writer.writerow(['Parent Link', 'Parent Title', 'Child Link', 'Child Title'])  # added

        for i in range(len(self.parentName)):
            writer.writerow([self.parentLinks[i].encode(encoding = 'UTF-8', errors = 'strict'), self.parentName[i].encode(encoding = 'UTF-8', errors = 'strict'), self.childLinks[i].encode(encoding = 'UTF-8', errors = 'strict'), self.childName[i].encode(encoding = 'UTF-8', errors = 'strict')])

        datafile.close()
        print('hello')

d = WebScrape()
d.scrapeWiki()
d.createCSV()