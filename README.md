# Havaalanı Kontrol Sistemi

## Öncelikli Kuyruk Yapısına genel bir bakış | (Tolgahan Çepel)

Bilginin geliş sırasına göre, ilk önce gelen elemana ilk erişilen liste yapısına kuyruk (queue) denir.
![1_Mtk98BdiSCAIqVG7FnBzLw](https://user-images.githubusercontent.com/81527587/165852492-acb31df9-4abd-492b-b6bd-f87bad260741.jpg)
Bu erişimde First-In-First-Out (FIFO) prensibi vardır. Yani ilk giren eleman, ilk çıkar. Örneğin sinema bileti almak için sıraya girmiş kişileri düşünebiliriz. İlk önce gelen kişi bileti daha önce alacaktır.
Queue veri yapısında, verilere iki uçtan erişim vardır. Bir uçtan eleman ekleme (enqueue), diğer uçtan eleman çıkarma (dequeue) işlemleri yapılır.
Queue tasarımı dizi veya bağlı liste ile yapılabilir. Bağlı liste kullanarak boyutu sabit olmayan bir queue oluşturabiliriz. Dizi kullanmak için ise sabit bir boyut belirlemeliyiz.
Öncelikli Kuyruk (Priority Queue)
Bazı problemlerin çözümünde doğrudan kuyruk oluşturamayız. Örneğin uçakların inişi sırasında, acil inmesi gereken uçaklar bulunabilir. Veya muayene sırasında bekleyen hastalar için farklı bir öncelik belirlenebilir.
Bu gibi senaryolarda öncelikli kuyruk ile çözüm üretilir. Öncelik sırası belirlenir ve program sırasında uygulanır.
UYGULAMA
Konuyu daha iyi anlatabilmek için, bağlı liste ile gerçekleştirilmiş bir queue uygulaması anlatacağım. İşlemler:
Eleman Ekle (enqueue)
Eleman Çıkar (dequeue)
Sıradaki Elemanı Getir (peek)
Genel anlamda queue (kuyruk) aşağıdaki gibi görünecek.
![1_o2xBRxkMaE1R3Yg4_7YhBg](https://user-images.githubusercontent.com/81527587/165852623-b4a11d34-20ab-4ead-ab84-d7b0d7cb12b9.jpg)
front (ön): kuyruğun önündeki elemanı gösteren işaretçi.
rear (arka): kuyruğun arkasındaki elemanı gösteren işaretçi
1. Eleman Ekle (enqueue)
Eleman ekleme işlemi için enqueue (kuyruğa eklemek) terimi kulanılır. Enqueue işlemininin kodlarını görelim.
![1_yw5wIIT49c493fkIUqYDWw](https://user-images.githubusercontent.com/81527587/165852784-618e5215-a211-45fb-8786-2da77dd50a80.png)
Öncelikle kuyruğun boş olduğu durumunu kontrol etmeliyiz. Eğer kuyruk boş ise (rear elemanı NULL ise) boş bir kuyruğa eleman ekleme işlemi yapacağız.
if(rear == NULL)
{
     front = rear = new struct node();
     rear->data = key;
}
Boş bir kuyruğa eleman eklersek enqueue(36); aşağıdaki gibi gözükecektir.
![1_e2ffaRs2pXcm9tq9ceo9gQ](https://user-images.githubusercontent.com/81527587/165852923-3abb8bad-297e-43dc-b3c0-8cce88248e3b.jpg)
Eğer kuyruk boş değilse: yeni bir düğüm oluşturmalı ve bu düğümü kuyruğun en arkasına eklemeliyiz.
else
{
     struct node* temp = new struct node();
     temp->data = key;
     rear->next = temp;
     rear = temp;
}
Düğüm ekleme konusunu anlamakta zorlanıyorsanız, Bağlı Liste (Linked List) konusunu inceleyebilirsiniz.
Yalnızca 36 elemanını eklemiştik. Şimdi birkaç ekleme yapalım ve nasıl göründüğünü inceleyelim.
enqueue(37);
![1_vxtAWRJp1_QNuuCiwPjo3w](https://user-images.githubusercontent.com/81527587/165852959-7a03b7be-850d-47ac-ae93-6ce2d9e6ec13.jpg)

enqueue(38);
enqueue(39);
enqueue(40);
![1_XHn16g7gU36bSm3ovFThxQ](https://user-images.githubusercontent.com/81527587/165852995-55176004-d1e5-45bf-9780-8ad2da2bccd5.jpg)

2. Eleman Çıkar (dequeue)
Eleman çıkarma işlemi için dequeue (kuyruktan çıkarmak) terimi kulanılır. Dequeue işlemininin kodlarını görelim.
![1_NIau_hmIXKlpLRCi2cH1pQ](https://user-images.githubusercontent.com/81527587/165853049-e9588e41-ebbd-4415-b72e-d912f45fa9cc.png)

Öncelikle kuyrukta yalnız bir eleman olduğu durumu kontrol etmeliyiz. Eğer kuyrukta tek eleman varsa (front’un sonraki NULL ise) tek elemanı doğrudan sileceğiz.
if(front->next == NULL)
{
     delete front;
     front = rear = NULL;
     return;
}
Bu işlemden sonra, kuyruk boş bir hâle gelecektir.
Eğer kuyrukta sadece bir eleman yoksa; en öndeki elemanı temp isminde saklamalı, bir sonraki elemanı yeni front elemanı olarak atamalı, son olarak sakladığımız elemanı silmeliyiz.
struct node* temp = front;
front = temp->next;
delete temp;
Örneğin aşağıdaki kuyruktan eleman silelim.
![1_XHn16g7gU36bSm3ovFThxQ](https://user-images.githubusercontent.com/81527587/165853179-7c112b4f-a108-484b-8b31-7c69f17c9796.jpg)

dequeue() işlemini uyguladığımızda, tek eleman olmadığı için if bloğuna girmez.
struct node* temp = front;
![1_MVWUjgW6ZxXA5jvYeynWQA](https://user-images.githubusercontent.com/81527587/165853218-c92e5c51-3525-4a76-a415-c7e63c6f1fda.jpg)

front = temp->next;
![1_lCIR3rTp_SUP4UQsKxALqw](https://user-images.githubusercontent.com/81527587/165853268-a618bc7b-3112-4797-98f9-9654f3466286.jpg)

delete temp;
![1__DbazQ92Xyh0Pf5k88ylTw](https://user-images.githubusercontent.com/81527587/165853282-5a3760a1-2f10-4402-9fc6-685fded1eb68.jpg)

Kuyruğun sol hâli aşağıdaki gibi olacaktır.
![1_s1p2sF2uRVMLNLpDddTSJw](https://user-images.githubusercontent.com/81527587/165853301-13bb662c-a1ec-479d-b084-18eab583dd20.jpg)

Birkaç işlem daha uygulayalım.
dequeue();
dequeue();
![1_sH7jxRJD1mlZJ8zSoH3qHw](https://user-images.githubusercontent.com/81527587/165853324-b7350941-c16b-404f-9773-8513428f92a9.jpg)

enqueue(41);
enqueue(42);
dequeue();
enqueue(43);
![1_Toi8b_64_J3r6wmCnWWvdg](https://user-images.githubusercontent.com/81527587/165853353-7b2b559d-5f96-47ba-ab96-c3f35b142bdb.jpg)

3. Sıradaki Elemanı Getir (peek)
![1_sN4RxluLKVhlf8DPclhy_A](https://user-images.githubusercontent.com/81527587/165853379-8c3e17fe-1873-4df6-961f-f05cf8c3560d.png)

Sıradaki eleman, front olarak tuttuğumuz düğüm demektir. Dolayısıyla front düğümünün değerini return ile döndürürsek, silme işlemi uygulamadan sıradaki elemanı elde ederiz.
Avantajları:
Geliş sırasına göre hizmet verilmesi gereken senaryolarda avantajlıdır.
Üretici-tüketici problemlerinde fayda sağlar.
Hastanelerde, uçakların inişinde, araç geçişlerinde öncelikli kuyruk kullanılabilir.
Dezavantajları:
Üzerinde arama yapmak zahmetlidir. En baştan başlanıp ilerlemek gerekir.
Kuyruğun aralarına eleman eklemek karmaşıktır.
Kullanım Alanları:
İşletim sistemlerinde çalışma önceliği kuyruk ile yapılır.
Ağ yazıcılarında, belgeler öncelikli kuyruk ile çalışır.
Asansör yazılımı kuyruk ile yapılabilir.
Sonuç
Bu yazımda queue (kuyruk) veri yapısına ve bağlı liste üzerinde uygulamasına değindim. Veri yapısının mantığı anlaşılırsa kolaylıkla dizi ile uygulanabilir.
