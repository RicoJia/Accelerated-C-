a. Working on branches (versions)
            0. git clone -b branch_name repo_name
            1. git branch -a                                check all existing branches in your repo directory;  * means current branch; HEAD is the pointer pointing to your current branch
            2. git checkout -b new_branch_name              create a new branch and switch there
            3. git checkout exisiting_branch
            4. ls                                           check out the files in the exisiting directory
            5. git branch -d branch_name                    delete a local branch

b. commit the branch (saves)
            0. git show file_name                               show the file content    
            0.5. git log                                        show all commit history
            1. touch file_name                                  create a new file. Question: create new file on new branch, but it also shows up on the old branch????
            2. git status                                       check out files that are added. 
            3. git add filename                                 stage the new file. nothing being added right now but it's telling git that it's going to add something for commit
            4. git config --global user.name "name"             git needs your info
            git config --global user.email "email"           
            5. git commit -m "message"                          commit with a message
            5(Optional). git config --global core.editor "editor name"      edit the commit message 
        

c. Merge changes locally
            0. make sure everything is commited or stashed
            1. git merge --no-ff                                ????

d. Push to remote
            1.git push origin new_branch_name                  push a new branch to this website

e. pull request to merge into master??

2. Working on forks (the entire repo with all branches)
