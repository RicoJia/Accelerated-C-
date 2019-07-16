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
            5. git commit -m "message"                          commit with a message. BE SURE IT's IN YOUR BRANCH!!
            5(Optional). git config --global core.editor "editor name"      edit the commit message 
        

c. Merge two branches locally       ???
            0. git stash                                       save your work aside for working on higher priority tasks. make sure everything is commited or stashed
               git stash list                                  check out a list of stashes
                        git stash apply stash@{0}                       you can save the changes back to your branch
                        git stash pop                                   or you delete it.          
            1. git merge branchB                               on branch B, merging branch A

d. Push to remote
            1.git push origin new_branch_name                  push a new branch to this website
            1(optional). $ git remote add [name_of_your_remote] [name_of_your_new_branch]
                         $ git push [name_of_your_new_remote] [url]
            

e. pull request to merge into master??


f. Get update from remote to local branch
            1. git fetch [name_of_your_remote]

g. Delete a branch remotely
            2. git push origin --delete branch_name
            
2. Working on forks (the entire repo with all branches)

Z. BUGS
            1. conflict (add/add): 
            git diff                                                    check out the differences 
            git diff branch1 branch2                                    then delete the wrong file
            Then go to your branch, check out the <<<<< ==== >>>> marked lines, Edit them
            git add.
            git commit -m "fixed conflict"
            
            
