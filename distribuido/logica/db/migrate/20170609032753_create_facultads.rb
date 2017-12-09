class CreateFacultads < ActiveRecord::Migration[5.0]
  def change
    create_table :facultades do |t|
      t.string :sigla
      t.string :nombre

      t.timestamps
    end
  end
end
