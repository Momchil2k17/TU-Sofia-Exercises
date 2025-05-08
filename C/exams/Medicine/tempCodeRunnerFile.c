for (int i = 0; i<count; i++) {
            printf("Medicine Name: %s\n", medicines[i].Name);
            printf("Expiry Date: %s\n", medicines[i].Date);
            printf("Code: %lld\n", medicines[i].Code);
            printf("Price: %.2f\n", medicines[i].Price);
            printf("Quantity: %d\n", medicines[i].Quantity);
            printf("-------------------------\n");
        }