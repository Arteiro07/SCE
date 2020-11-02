# SCE

Project SCE 2020

## Instalation

* `git@github.com:Arteiro07/SCE.git`
* `cd SCE`

Now you can use git commands:

* `git checkout -b <branch_name>` - create new branch with branch_name name;
* `git push --set-upstream origin <branch_name>` - push the branch to the repository;
* `git checkout branch_name` - change branch to the banch name;
* `git branch` - see in wich branch are you working on;
* `git status` - see which files you changed from last push, and which ones are ready to commit;
* `git add <file>` - add changes to the next commit (the file doesn't need to be the full path, ex: Aval/aval1 => git add Aval);
* `git reset HEAD <file>`- reset the git add to that file, in case of mistake;
* `git checkout -- <file>` - to discard alterations in that file;
* `git commit` - oppens a window to write the description of the commit, start by writing, when you finish, press ESC and type ':wq' to save changes and exit;
* `git push` - push the commit (aka changes) to the branch (push==upload);
* `git pull` - pulls the files from certain branch to your folder (pull==download);
* `git log` - check the previous commits, note that you can change to certain commit with `git checkout`;

Notes:
1.  Remember to commit and push changes when you finish doing your changes;
2.  You can Merge Request in the gitlab website, it's easier.
