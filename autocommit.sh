echo "Github Automation";
echo "Please enter the commit message:";
read var1;
git pull origin master;
git add .;
git commit -m "$var1";
git push origin master;
echo "Github sux";
