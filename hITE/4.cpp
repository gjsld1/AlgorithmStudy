//
//  4.cpp
//  hITE
//
//  Created by 신예지 on 2020/05/10.
//  Copyright © 2020 신예지. All rights reserved.
//

SELECT CART_ID, IF(SUM(PRICE)<50000, SUM(PRICE)+3000, SUM(PRICE)) AS '결제액'
FROM CART_PRODUCTS
GROUP BY CART_ID
ORDER BY CART_ID;
