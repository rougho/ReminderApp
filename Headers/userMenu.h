
 void userMenu(){

while(true){
    int userChoice;
    printf("\n\t---------------------------------------------------------------\n");
    printf("\t----                1. add event                           ----\n");
    printf("\t----                2. Calender                            ----\n");
    printf("\t----                3. look events                         ----\n");
    printf("\t----                4. delete                              ----\n");
    printf("\t----                5. search                              ----\n");
    printf("\t----                6. exit                                ----\n");
    printf("\t---------------------------------------------------------------\n");

        printf("\n\n\t->Choose an Option[1-6]:");
        scanf("%d",&userChoice);
        switch(userChoice){
        case 1:
            anniversaryUserInput();
            break;
        case 2:
            Calender();
            break;
        case 3:
            lookEvents();
        break;
        case 4:
            Delete();
        break;
        case 5:
            userWordCheck();
            getchar();
        break;
        case 6:
            exit(0);
        default:
            printf("\tplease write a valid input\n");
            break;
        }
    }
 }
