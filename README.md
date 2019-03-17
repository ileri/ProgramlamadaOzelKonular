# Programlamada Özel Konular Kütüphane Kodları

Bu repo, Ondokuz Mayıs Üniversitesi Bilgisayar Mühendisliği Programlamada Özel
Konular dersi kapsamında dönem boyunca labaratuvarda yazılan kod örnekleri ve
bu örneklere konudan fazla uzaklaşmadan şahsım tarafından yapılabilecek ekleme
veya düzenlemeleri içermektedir.

## Genel Yapı

Bu projede amaç, günlük hayattaki gerçek projelere benzer gelişmiş bir
kütüphane yazımı ve yönetimini öğrenmektir.

Kodlar labaratuvar eğitimi süresince kısıtlı süre içerisinde yazılmakta olup
gerçek projelerde kullanıma uygunluğu test edilmemiştir.

### Dizin Yapısı

Proje, ana dizin de dahil olmak üzere 3 temel dizinden oluşmaktadır.

**src** dizini temel fonksiyonları ve kütüphane dosyalarını içermektedir.

**test** dizini ise *src* dizininde yazılmış olan kodların kullanımının test
edilmesi için gerekli fonksiyonları içermektedir.

**Ana dizin** ise Makefile başta olmak üzere derleme ve ayar dosyalarını
içermektedir. Derlenmiş kodlar da ilk aşamada ana dizinde saklanmakta olup
ileriki aşamalarda alt bir dizine taşınması söz konusu olabilir.

### Projenin Derlenmesi

Proje, Makefile içermekte olup tek komut ile derlenebilmektedir.

~~~sh
make
~~~

Yukarıdaki komutu kullanarak projeyi derleyebilirsiniz.

Proje derlendiğinde **mattest** isimli bir çalıştırılabilir derlenmiş ikili
dosya oluşacaktır.

Bu dosyayı da aşağıdaki komut ile çalıştırabilirsiniz.

~~~sh
./mattest
~~~


Yada daha kısa bir yol olarak, hem derleyip hem çalıştırmak için

~~~sh
make run
~~~

komutunu kullanabilirsiniz.

Projedeki derlenmiş obje ve kütüphane dosyaları ve çalıştırılabilir dosyaları
temizlemek için ise aşağıdaki konutu kullanabilirsiniz.

~~~sh
make clean
~~~
