from urllib.request import urlopen
import requests
from bs4 import BeautifulSoup
import re
import csv
import numpy as np

class WebScrape():
    def __init__(self):
        self.parentLinks = [] #list that will store all the parent links
        self.parentName = [] #list that will store all the parent names
        self.childLinks = [] #list that will store all the child links [child links that come from the parent link]
        self.childName = [] #list that will store all the child names
        self.weights = [] #list that will store the weights for the graph
        self.startingIndex = [] #list that will store the starting index for the parent or child 

    def scrapeWiki(self):

        url = 'https://en.wikipedia.org/wiki/Ladder' #The starting parent link
        website_url = requests.get(url).text
        soup = BeautifulSoup(website_url, "lxml")

        parentLink = 'https://en.wikipedia.org/wiki/Ladder' #The starting parent link
        parentTitle = 'Ladder'
        self.startingIndex.append(0)

        #Each wikipedia link consists of "<a href=/wiki/"CHILD_LINK" title = "CHILD_NAME" ". This for loop is finding all of those elements within the console
        for link in soup.find_all('a'): 
            #These if statments remove outliers that will mess up the format of our output because some links have ":" or "?" which aren't proper links
            # We will only be accessing the clean links 
            if ((link.get('title') is not None) and (':' not in link.get('href'))): 
                if ((':' not in link.get('title')) and ('?' not in link.get('href'))):
                    if (('Main_Page' not in link.get('href')) and ('identifier' not in link.get('title')) and (
                            'content' not in link.get('title'))):
                        if (link.get('title') not in self.childName):
                            #All of this will be added to the CSV file so our C++ will be able to use it
                            self.parentLinks.append(parentLink) #We are continously adding the parentLink to the list  
                            self.parentName.append(parentTitle) #We are continously adding the parentTitle to the list  
                            self.childLinks.append('https://en.wikipedia.org' + link.get('href')) #We are continously adding the childList to the list in the format there so our link will be an actual link
                            self.childName.append(link.get('title')) #We are continously adding the childName to the list  

        for i in range(1000): 
            # 
            url = self.childLinks[i] #the starting URL, the first child for each parent will become the next parent 
            website_url = requests.get(url).text
            soup = BeautifulSoup(website_url, "lxml")

            parentLink = url
            parentTitle = self.childName[i]
            self.startingIndex.append(len(self.childName))

            #Each wikipedia link consists of "<a href=/wiki/"CHILD_LINK" title = "CHILD_NAME" ". This for loop is finding all of those elements within the console
            for link in soup.find_all('a'): 
                #These if statments remove outliers that will mess up the format of our output because some links have ":" or "?" which aren't proper links
                # We will only be accessing the clean links 
                if ((link.get('title') is not None) and (':' not in link.get('href'))): 
                    if ((':' not in link.get('title')) and ('?' not in link.get('href'))):
                        if (('Main_Page' not in link.get('href')) and ('identifier' not in link.get('title')) and (
                                'content' not in link.get('title'))):
                            if (link.get('title') not in self.childName):
                                #All of this will be added to the CSV file so our C++ will be able to use it
                                self.parentLinks.append(parentLink) #We are continously adding the parentLink to the list  
                                self.parentName.append(parentTitle) #We are continously adding the parentTitle to the list  
                                self.childLinks.append('https://en.wikipedia.org' + link.get('href')) #We are continously adding the childList to the list in the format there so our link will be an actual link
                                self.childName.append(link.get('title')) #We are continously adding the childName to the list  

        for j in range(len(self.parentLinks)): 
            parentTitle = self.parentName[j]
            startIndexParent = self.parentName.index(parentTitle)
            if (startIndexParent == self.startingIndex[-1]):
                arr2 = self.childName[startIndexParent:]
                endIndexParent = len(arr2)
            else:
                endIndexParent = self.startingIndex[self.startingIndex.index(startIndexParent) + 1] - 1
            length = endIndexParent - startIndexParent
            self.weights.append(length)

    

    def createCSV(self):
        datafile = open("Dataset.csv", "w")
        writer = csv.writer(datafile)
        writer.writerow(['Parent Link', 'Parent Title', 'Child Link', 'Child Title, Weights'])  # added
        print(len(self.weights))
        print(len(self.parentName))
        for i in range(len(self.parentName)):
            writer.writerow([self.parentLinks[i].encode(encoding='UTF-8', errors='strict'),
                             self.parentName[i].encode(encoding='UTF-8', errors='strict'),
                             self.childLinks[i].encode(encoding='UTF-8', errors='strict'),
                             self.childName[i].encode(encoding='UTF-8', errors='strict'),
                             self.weights[i]])

        datafile.close()


d = WebScrape()
d.scrapeWiki()
d.createCSV()
