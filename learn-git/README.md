# Learn git usage

## Configure the git

```

```


## To check your remote origin and your upstream origin

```
$ git remote -v

```

## To sync your forked repository with original repository

```
$ git remote add upstream https://github.com/name/repo_name.git
$ git fetch upstream
$ git checkout master
$ git rebase upstream/master
$ git push -f origin master

```

## change remote origin of your git repository

```
$ git remote rm origin
$ git remote add origin git@github.com:aplikacjainfo/proj1.git
$ git config master.remote origin
$ git config master.merge refs/heads/master

After this you can push your commits to new repository location

$ git push

```

