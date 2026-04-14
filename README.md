# 📘 StudyBuddy – Smart Study Planner

> A simple and structured C++ tool to plan, track, and complete your studies efficiently.

---

## ✨ Overview
StudyBuddy is a console-based application that helps students organize their study plan based on chapter difficulty and track their daily progress.

It focuses on clarity, consistency, and realistic study planning.

---

## 🚀 Features
- 📂 Categorizes chapters into Easy, Medium, and Hard  
- ✍️ Allows input of chapter names  
- 📅 Distributes chapters across study days  
- 📊 Tracks progress percentage  
- 🔁 Includes a final revision day  
- 💬 Provides simple progress feedback  

---

## ⚙️ How It Works

1. Enter total chapters and study days  
2. Enter number of Easy, Medium, and Hard chapters  
3. Input chapter names for each category  
4. Follow the daily plan generated  
5. Mark chapters as completed (Y/N)  
6. Track your progress step-by-step  

---

## 🧪 Sample Output
========================================
 StudyBuddy - Your Study Compass
========================================

Enter total chapters: 10
Enter study days: 3

Enter EASY chapters: 5
Enter MEDIUM chapters: 3
Enter HARD chapters: 2

Enter chapter names (HARD first, then MEDIUM, then EASY):
Hard chapter 1: Constructor
Hard chapter 2: Destructor
Medium chapter 1: visibility modes
Medium chapter 2: OOP
Medium chapter 3: Modules
Easy chapter 1: Specification
Easy chapter 2: Algorithm
Easy chapter 3: Flowchart
Easy chapter 4: Abstraction
Easy chapter 5: Procedural programming

========================================
 STUDY PLAN
========================================

Day 1
----------------------------------------
Study: Constructor [HARD]
Completed? (Y/N): y
[✓] Marked complete
Study: Destructor [HARD]
Completed? (Y/N): y
[✓] Marked complete
Study: visibility modes [MEDIUM]
Completed? (Y/N): y
[✓] Marked complete
Study: OOP [MEDIUM]
Completed? (Y/N): y
[✓] Marked complete
Study: Modules [MEDIUM]
Completed? (Y/N): y
[✓] Marked complete

Progress: 50.0%
Half way there. Keep going.

Day 2
----------------------------------------
Study: Specification [EASY]
Completed? (Y/N): y
[✓] Marked complete
Study: Algorithm [EASY]
Completed? (Y/N): y
[✓] Marked complete
Study: Flowchart [EASY]
Completed? (Y/N): y
[✓] Marked complete
Study: Abstraction [EASY]
Completed? (Y/N): y
[✓] Marked complete
Study: Procedural programming [EASY]
Completed? (Y/N): y
[✓] Marked complete

Progress: 100.0%
Super amazing. All done.

Day 3
----------------------------------------
Revision Day
Revise all chapters

Progress: 100.0%
Super amazing. Revision time.

[Program finished]
