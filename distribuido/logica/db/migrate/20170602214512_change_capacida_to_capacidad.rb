class ChangeCapacidaToCapacidad < ActiveRecord::Migration[5.0]
  def change
    rename_column :salas, :capacida, :capcidad
  end
end
