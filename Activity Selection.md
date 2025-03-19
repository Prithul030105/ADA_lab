The Activity Selection Problem is a greedy algorithm problem where we are given N activities, each with a start time and end time. The goal is to select the maximum number of non-overlapping activities.

Problem Statement
You are given N activities, each defined by a start time and an end time. Only one activity can be selected at a time, and an activity cannot overlap with another selected activity. Your task is to find the maximum number of activities that can be performed.

Approach (Greedy Algorithm)
To solve this problem efficiently, we use the Greedy Algorithm:

Sort the activities based on their end time (earliest finishing first).
Select the first activity (since it finishes earliest).
Iterate through the remaining activities:
If an activity starts after or when the last selected activity ends, select it.
Update the end time of the last selected activity.
Repeat until all activities are checked.
