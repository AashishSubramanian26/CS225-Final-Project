from urllib.request import urlopen
import requests
from bs4 import BeautifulSoup
import re
import csv
import numpy as np

class WebScrape():
    def __init__(self):
        self.parentLinks = []
        self.parentName = []
        self.childLinks = []
        self.childName = []
        self.weights = []
        self.startingIndex = []

    def scrapeWiki(self):
        url = 'https://en.wikipedia.org/wiki/Ladder'
        website_url = requests.get(url).text
        soup = BeautifulSoup(website_url, "lxml")

        parentLink = 'https://en.wikipedia.org/wiki/Ladder'
        parentTitle = 'Ladder'
        self.startingIndex.append(0)

        # Each wikipedia link consists of "<a href=/wiki/"CHILD_LINK" title = "CHILD_NAME" ". This for loop is finding all of those elements within the console
        for link in soup.find_all('a'):
            # These if statments remove outliers that will mess up the format of our output because some links have ":" or "?" which aren't proper links
            # We will only be accessing the clean links
            if ((link.get('title') is not None) and (':' not in link.get('href'))):
                if ((':' not in link.get('title')) and ('?' not in link.get('href'))):
                    if (('Main_Page' not in link.get('href')) and ('identifier' not in link.get('title')) and (
                            'content' not in link.get('title'))):
                        if (link.get('title') not in self.childName):
                            # All of this will be added to the CSV file so our C++ will be able to use it
                            self.parentLinks.append(parentLink) #We are continously adding the parentLink to the list
                            self.parentName.append(parentTitle) #We are continously adding the parentTitle to the list
                            self.childLinks.append('https://en.wikipedia.org' + link.get('href')) #We are continously adding the childList to the list in the format there so our link will be an actual link
                            self.childName.append(link.get('title')) #We are continously adding the childName to the list

        for i in range(200):
            url = self.childLinks[i] #the starting URL, the first child for each parent will become the next parent
            website_url = requests.get(url).text
            soup = BeautifulSoup(website_url, "lxml")

            parentLink = url
            if(parentLink in self.parentLinks):
                continue
            parentTitle = self.childName[i]
            self.startingIndex.append(len(self.childName))

            # Each wikipedia link consists of "<a href=/wiki/"CHILD_LINK" title = "CHILD_NAME" ". This for loop is finding all of those elements within the console
            for link in soup.find_all('a'):
                # These if statments remove outliers that will mess up the format of our output because some links have ":" or "?" which aren't proper links
                # We will only be accessing the clean links
                if ((link.get('title') is not None) and (':' not in link.get('href')) and (',' not in link.get('href'))):
                    if ((':' not in link.get('title')) and ('?' not in link.get('href'))):
                        if (('Main_Page' not in link.get('href')) and ('identifier' not in link.get('title')) and (
                                'content' not in link.get('title')) and (',' not in link.get('title'))):
                            if((',' in link.get('title'))):
                                continue
                            # All of this will be added to the CSV file so our C++ will be able to use it
                            self.parentLinks.append(parentLink) #We are continously adding the parentLink to the list
                            self.parentName.append(parentTitle) #We are continously adding the parentTitle to the list
                            self.childLinks.append('https://en.wikipedia.org' + link.get('href')) #We are continously adding the childList to the list in the format there so our link will be an actual link
                            self.childName.append(link.get('title')) #We are continously adding the childName to the list

        for j in range(len(self.parentLinks)):
            parentTitle = self.parentName[j];
            startIndexParent = self.parentName.index(parentTitle)

            if (startIndexParent == self.startingIndex[-1]):
                arr2 = self.childName[startIndexParent:]
                endIndexParent = len(arr2)
            else:
                endIndexParent = self.startingIndex[self.startingIndex.index(startIndexParent) + 1] - 1
            length = endIndexParent - startIndexParent
            self.weights.append(length)
        index = 0
        while(index < len(self.parentName)):
            if (index > len(self.parentName) - 1):
                break
            if ("%" in self.parentLinks[index] or "%" in self.childLinks[index] or "wikimedia" in self.childLinks[index] or "\"" in self.parentName[index] or "\"" in self.childName[index]):
                self.parentLinks.pop(index)
                self.parentName.pop(index)
                self.childLinks.pop(index)
                self.childName.pop(index)
                self.weights.pop(index)

            else:
                index = index+1


    def createCSV(self):
        datafile = open("Dataset.csv", "w")
        writer = csv.writer(datafile)
        writer.writerow(['Parent Link', 'Parent Title', 'Child Link', 'Child Title', 'Weights'])  # added
        for i in range(len(self.parentName)):
            if (i==0 or self.weights[i]<0):
                continue
            try:
                writer.writerow([self.parentLinks[i],
                                 self.parentName[i],
                                 self.childLinks[i],
                                 self.childName[i],
                                 self.weights[i]])
            except:
                pass

        datafile.close()


d = WebScrape()
d.scrapeWiki()
d.createCSV()
