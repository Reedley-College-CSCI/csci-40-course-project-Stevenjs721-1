[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7mdzU3H2)
# CS1 Final Project - [Movie Library]

## 1. Overview
- What problem does your project solve?  
- Briefly describe the purpose and key features of your program.  

My project is a way to keep track of the movies that you've watched or the movies that you might want to watch. 
It allows you to get a bird's eye view of what you've watched through the years and collect all your favorite movies. 
Although the project is simple in nature, it can be applied to many larger projects like a movie library for a 
streaming service, a tracking system for movies you've watched, and a search engine for a specific class of movies. 
My project allows users to enter, remove, edit, view, search and sort movies. It allows users to easily look through and 
keep track of larger collections of movies.

---

## 2. Design Decisions
- What fundamental programming constructs and data types did you use, and why?  

The data types I used were ints, strings, bool, and char. The programming constructs I used were structs,
classes, arrays, void and int functions, and for selection I used if-statements and switch cases, and for
iterating I used while-loops and for-loops.

- Why did you choose to structure your data using structs?  

I decided to use structs because they would be able to hold multiple related variables in one variable
that I could then use as a storage for a movie. It allowed me to create an array of structs that acted as 
the storage of movies and their information.

- How did you implement searching and sorting? What algorithms did you use and why?  

I implemented searching in my update, remove, and search functions and allowed users to find a movie easily
through the library and remove or update them in different areas of the library. I used a linear sort 
because a binary sort would mean I would have to sort the movies alphabetically and then search from there.
I understand that there may be problems that arise with uppercase letters and felt that the code would be 
built better with a linear sort. I also have sorting functions that are sorted alphabetically, year, and 
genre. After looking through zybooks I ended up using ASCII numbers to sort alphabetically and this same 
code was applied to genre as well. The year sort was unnecessarily hard since I had my year in a string. 
This was an error that I didn't realize until now and looking back I should have made sure the year 
remained an int. After trying a lot of things out, I ended finding out that I could use substr to pull out 
the number so that it could be compared properly. All of my sorts are selection sorts because selection 
sorts will work better for potentially larger movie libraries.

- How do you ensure data persistence between program runs?  

I used a single file to hold information and formatted it within the file to make some things easier. 
For a while I couldn't figure out how to edit the file, but I realized I could code in a new file that 
will replace the old one.  While the new file gets the old files information I could make changes by 
removing or adding things in the saving process.

- Did you consider alternative approaches? If so, why did you not use them?  

I did think about having the data unformatted in the file so that it could be easily manipulated in the code.
This would have saved me some trouble in other functions and made the cope a little simpler. Though I think 
formatting the data allowed for better testing and understanding of problems in the code. On a larger scale 
it might not be as useful to me but for this specific case at least I say it worked well.

---

## 3. Testing Summary
- **Structured Testing Log:** Include a table with test cases, expected output, actual output, and pass/fail status.  
- What testing methods did you use?  
- (Table with test cases in link)

https://1drv.ms/w/c/959cf94b5c52dc7b/EWmVJo6ZhtlHpgRpenRl76gBVwC01uyVUmRMtORD7IIqbQ?e=MOshEi 

- Provide examples of test inputs (valid and invalid) and describe how your program responds.  

I went through each section of the code and input any possible invalid inputs and checked to see if each 
function worked correctly. 

* Provide examples of test inputs (valid and invalid) and describe how your program responds.

* Example 1: Functionality
			TC-1-8 - Each test case checks to see if a function can work when given proper input. 
			It was shown that it works just fine. 
* Example 2: Invalid input
			TC-14- During development of code I made sure along the way that code would be able 
			to take incorrect input and let user try again. Although it is one test case, it was tested
			at least 10 times for each function of the code.
* Example 3: Bugs
			TC-13- When updating a movie you could input '0' as the name but it could not be searched, 
			and therefore could not be edited or removed. To fix the function catches variable, 
			currName, before input and outputs a return if it equals '0'

---

## 4. Technical Walkthrough
- Explain the main functionality of your program.  

When the program starts users are prompted to enter 0-4 for different functions.
Inputting 1 brings you to the library where you can input 1 to sort, 2 to search,
and 0 to exit the library. Within the sort function you can enter 0-3 to sort by
name, genre, year or exit to the menu. Entering 2 in the main menu lets you input
movies to the function where you input the name, genre, and year. Within the remove 
and update section you input a movie name in the library to modify it. There are many
confirmations to make sure the user doesn't input errors. You can enter '0' to exit in
all inputs that explicitly say so.

- **Include a link to your required video demonstration** showcasing how the project works (**3-7 minutes**). 
    Make sure it shareable without approval needed.
	https://youtube.com/live/qEb8YS7IVB0 
---

## 5. Challenges and Lessons Learned
- What challenges did you encounter while working on this project?  

I had a lot of problems with the data filing and updating. There were a lot of problems with 
   using getlines and these problems would create more problems in other functions. Though I learned
   how to format the data and unformat it to make sure everything worked. Another thing was editing 
   the data because I didn't know how to access different parts of the text file. It took me a while 
   before I realized I could make a new file and apply changes when moving the data over. This problem
   probably was the most frustrating because I went through many solutions before I finally found the right one.

- What key lessons did you learn about programming and problem-solving?  

One key lesson I learned was how important planning ahead of time is. I didn't really plan and just 
   tried to tackle one thing at a time, and this did work well. Though there were times when I felt 
   overwhelmed about what I should be doing, and I had to change my code a lot because I didn't plan 
   for each part to work together well. Another key lesson I learned was how important it is to go over 
   past code to test bugs. On every part of my code, I went back at least once to fix problems that I had 
   not seen before. I periodically tested all the code I had to see if I could find more bugs and I usually 
   did, even in ones that I had fixed many times.

---

## 6. Future Improvements
- If you had more time, what changes or enhancements would you make?  

In my initial plans I wanted to implement a 'rating' and 'have watched' variable along with the movie information.
   However, due to lack of time and specific designing I wanted to do, I never got to put those variables in. I think
   it would have added a lot if I got it in there, but the finished product is still good. I think I would also adjust 
   some of the code to be smaller and less redundant. There are parts that could be taken out or made smaller.
   Though everything runs good as far as I've seen so this adjustment would be non-essential.




    ---- Given $1,000 to distribute among yourself and your partner, how much would give each of you and why? 

   Include detail on who did what throughout the design and development process. If you worked alone, please provide an 
   introspective paragraph how how effective you were, what went well, what could have gone better.

   I worked on this project by myself so I would get the full 1000. I feel like I was pretty effective with my time 
   considering that this was my first project. I didn't plan much and just started creating rough drafts of functions.
   This may have caused me to struggle and deal with some avoidable problem but I think that it allowed me to go through
   the process of coming up with an idea, putting it into code, and fixing whatever bugs it may have very quickly. I worked
   on what I could and when I got stuck it would take a while but I would learn from it and could apply it to other parts 
   of my code. The file handling and looping aspect of the project when really well. They both felt intuitive and whenever I
   was confused it didn't take long for me to figure it out. I thought the looping aspect of the code would be messy and 
   produce a lot of problems but I handled it pretty well and made sure everything was cleanly done. I think that the formatting
   of the data could have been better. Using getlines made a lot of stuff complicated when it could have been avoided. This
   made it annoying to pull out information directly without the formatting. It wasn't horrible but it could have been better. 
   Overall I'm pretty proud of my project and thing if I had more time it could have been an even more polished project. 

